/*
 * DHT_Sensor.c
 *
 *  Created on: 25-Apr-2026
 *      Author: dhany
 */
#include "DHT_Sensor.h"


#define DHT_PORT 	GPIOA
#define DHT_PIN  	GPIO_PIN_1

static void DHT_SetOutput(void);
static void DHT_SetInput(void);


/* USER CODE BEGIN 0 */
void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim2, 0);

    while (__HAL_TIM_GET_COUNTER(&htim2) < us);
}


static void DHT_SetOutput(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin   = DHT_PIN;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;        // No pull in output mode
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(DHT_PORT, &GPIO_InitStruct);
}

static void DHT_SetInput(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin  = DHT_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;         // 🔥 Enable internal pull-up
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(DHT_PORT, &GPIO_InitStruct);
}


t_Status DHT_Initialize(void)
{
    return STS_OK;
}

#define DHT_TIMEOUT_MS   2   // for long waits
#define DHT_TIMEOUT_US   100 // for bit-level waits


t_Status DHT_Read(UINT8 *temp, UINT8 *hum)
{
    uint8_t data[5] = {0};
    uint16_t timeout_us;

    // Step 1: Start signal
    DHT_SetOutput();
    HAL_GPIO_WritePin(DHT_PORT, DHT_PIN, GPIO_PIN_RESET);
    delay_us(18000);   // 18 ms (FIXED: was 18 us ❌)

    HAL_GPIO_WritePin(DHT_PORT, DHT_PIN, GPIO_PIN_SET);
    delay_us(50);

    DHT_SetInput();
    delay_us(10); // allow line to settle

    // Step 2: Wait for sensor response LOW (~80us)
    timeout_us = 0;
    while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN))
    {
        delay_us(1);
        if (++timeout_us > 200) return STS_ERROR;
    }

    // Step 3: Wait for sensor HIGH (~80us)
    timeout_us = 0;
    while (!HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN))
    {
        delay_us(1);
        if (++timeout_us > 100) return STS_ERROR;
    }

    // Step 4: Wait for sensor LOW (start of data)
    timeout_us = 0;
    while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN))
    {
        delay_us(1);
        if (++timeout_us > 100) return STS_ERROR;
    }

    // Step 5: Read 40 bits
    for (int i = 0; i < 40; i++)
    {
        // Wait for HIGH (bit start)
        timeout_us = 0;
        while (!HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN))
        {
            delay_us(1);
            if (++timeout_us > DHT_TIMEOUT_US)
                return STS_ERROR;
        }

        // Wait 40us and sample
        delay_us(40);

        if (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN))
            data[i/8] |= (1 << (7 - (i%8)));

        // Wait for LOW (bit end)
        timeout_us = 0;
        while (HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN))
        {
            delay_us(1);
            if (++timeout_us > DHT_TIMEOUT_US)
                return STS_ERROR;
        }
    }

    // Step 6: Checksum validation (ADDED)
    if ((uint8_t)(data[0] + data[1] + data[2] + data[3]) != data[4])
        return STS_ERROR;

    // Step 7: Assign values
    *hum  = data[0];
    *temp = data[2];

    return STS_OK;
}

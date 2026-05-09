/*
 * System.c
 *
 *  Created on: 25-Apr-2026
 *      Author: dhany
 */
#include "System.h"
#include "DHT_Sensor.h"
#include "CanIntf.h"

volatile UINT32 systemClockFreq = 0;

volatile UINT8  doorStatus_global = 0;


t_Status System_Init(void)
{
    t_Status status = STS_OK;

    /* Initialize the system components here */
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    // initialize system clock
    status = SystemClock_Config();

    if (status != STS_OK)
    {
        return status;
    }

    // Initialize GPIO
    MX_GPIO_Init();

    // timer initialization
    MX_TIM2_Init();

    // start timer
    HAL_TIM_Base_Start(&htim2);

    // Initialize DHT
    DHT_Initialize();

    // initialize CAN peripheral
    MX_CAN_Init();   // CubeMX generated

    // initialize CAN
    CAN_Interface_Init();

    // get system clock frequency
    systemClockFreq = HAL_RCC_GetSysClockFreq();

    // Optionally, you can add some debug logging here to verify the clock frequency
    // For example: printf("System Clock Frequency: %lu Hz\n", systemClockFreq);

    return status;
}

t_Status System_Run(void)
{
    t_Status status = STS_OK;

    /* USER CODE BEGIN PV */
    static uint32_t lastTick = 0;
    uint8_t temperature = 0;
    uint8_t humidity = 0;
    uint8_t Frame[8];
    float   temperature_float = 0;
    float   humidity_float = 0;
    uint8_t doorStatus = 0;

    while (1)
    {
        if(HAL_GetTick() - lastTick >= 10000)
        {
        	lastTick = HAL_GetTick();

        	__disable_irq();

        	status = DHT_Read(&temperature, &humidity);

        	__enable_irq();

#if 0
        	temperature_float = (float)temperature;
        	humidity_float = (float)humidity;
#else
        	temperature_float = (float)34;
        	humidity_float = (float)50;
#endif


        	memset(Frame, 0x00, sizeof(Frame));

        	Frame[0] = 0x01;
        	Frame[1] = 'T';
        	memcpy(&Frame[2], &temperature_float, sizeof(temperature_float));

        	//if(status == STS_OK)
        	{
        		CAN_Send(sizeof(Frame), Frame);
        	}

        	memset(Frame, 0x00, sizeof(Frame));

        	Frame[0] = 0x01;
        	Frame[1] = 'H';
        	memcpy(&Frame[2], &humidity_float, sizeof(humidity_float));

        	//if(status == STS_OK)
        	{
        		CAN_Send(sizeof(Frame), Frame);
        	}

        	memset(Frame, 0x00, sizeof(Frame));

        	doorStatus = (uint8_t)doorStatus_global;

        	Frame[0] = 0x01;
        	Frame[1] = 'D';
        	memcpy(&Frame[2], &doorStatus, sizeof(doorStatus));

        	//if(status == STS_OK)
        	{
        		CAN_Send(sizeof(Frame), Frame);
        	}
        }
    }

    /* Run the system */

    return status;
}

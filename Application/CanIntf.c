/*
 * CanIntf.c
 *
 *  Created on: 25-Apr-2026
 *      Author: dhany
 */

#include "CanIntf.h"




void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef rxHeader;
    uint8_t data[8];

    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rxHeader, data);

    if(rxHeader.StdId == 0x101)
    {
        if(data[0] == 1)
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    }
}


t_Status CAN_Interface_Init(void)
{
    CAN_FilterTypeDef filter;


    // Configure filter
    filter.FilterBank = 0;
    filter.FilterMode = CAN_FILTERMODE_IDMASK;
    filter.FilterScale = CAN_FILTERSCALE_32BIT;

    filter.FilterIdHigh = 0;
    filter.FilterIdLow = 0;
    filter.FilterMaskIdHigh = 0;
    filter.FilterMaskIdLow = 0;

    filter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    filter.FilterActivation = ENABLE;

    HAL_CAN_ConfigFilter(&hcan, &filter);

    // Start CAN
    HAL_CAN_Start(&hcan);

    // Enable RX interrupt
    HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING);

    return STS_OK;
}


t_Status CAN_Send(uint8_t temp, uint8_t hum)
{
    CAN_TxHeaderTypeDef txHeader;
    uint8_t data[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    uint32_t mailbox;

    txHeader.StdId = 0x100;
    txHeader.IDE = CAN_ID_STD;
    txHeader.RTR = CAN_RTR_DATA;
    txHeader.DLC = 8;

    // Check if mailbox is available
    if(HAL_CAN_GetTxMailboxesFreeLevel(&hcan) > 0)
    {
        if(HAL_CAN_AddTxMessage(&hcan, &txHeader, data, &mailbox) == HAL_OK)
        {
            return STS_OK;
        }
        else
        {
            return STS_ERROR;
        }
    }

    // No mailbox available
    return STS_ERROR;
}

/*
 * CanIntf.h
 *
 *  Created on: 25-Apr-2026
 *      Author: dhany
 */

#ifndef CAN_INTF_INCLUDE_CANINTF_H_
#define CAN_INTF_INCLUDE_CANINTF_H_

#include "Common.h"


t_Status CAN_Interface_Init(void);
t_Status CAN_Send(uint8_t temp, uint8_t hum);


#endif /* CAN_INTF_INCLUDE_CANINTF_H_ */

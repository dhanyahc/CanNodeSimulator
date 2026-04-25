/*
 * DHT_Sensor.h
 *
 *  Created on: 25-Apr-2026
 *      Author: dhany
 */

#ifndef DHT_SENSOR_INCLUDE_DHT_SENSOR_H_
#define DHT_SENSOR_INCLUDE_DHT_SENSOR_H_

#include "Common.h"


t_Status DHT_Initialize(void);
t_Status DHT_Read(UINT8 *temp, UINT8 *hum);


#endif /* DHT_SENSOR_INCLUDE_DHT_SENSOR_H_ */

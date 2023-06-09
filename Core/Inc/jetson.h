/*
 * jetson.h
 *
 *  Created on: May 9, 2023
 *      Author: deslo
 */

#ifndef INC_JETSON_H_
#define INC_JETSON_H_

#include "spi.h"
#include "gpio.h"
#include "sensors.h"
#include "hw_config.h"

typedef struct {
	SPI_HandleTypeDef 	*hspi;
	uint16_t 			cs_pin;

	uint8_t 			txBuf[SENSORS_MESSAGE_LENGTH];
	/* this will be only for the message address at this point; */
	uint8_t 			rxBuf[SENSORS_MESSAGE_LENGTH];
}Jetson_Struct;



void Jetson_Init(Jetson_Struct *jetson, SPI_HandleTypeDef *hspi, uint16_t cs_pin);
uint8_t Jetson_SendSensorData(Jetson_Struct *jetson, Sensors_Struct *sensors);


#endif /* INC_JETSON_H_ */

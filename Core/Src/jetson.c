/*
 * jetson.c
 *
 *  Created on: May 12, 2023
 *      Author: deslo
 */

#include "jetson.h"

void Jetson_Init(Jetson_Struct *jetson, SPI_HandleTypeDef *hspi, uint16_t cs_pin) {
	jetson->hspi = hspi;
	jetson->cs_pin = cs_pin;
}

uint8_t Jetson_SendSensorData(Jetson_Struct *jetson, Sensors_Struct *sensors) {
	Sensors_GenerateMessage(sensors, &jetson->txBuf);
//	while(HAL_SPI_GetState(jetson->hspi) != HAL_SPI_STATE_READY);
	return (HAL_SPI_Transmit_DMA(jetson->hspi, &jetson->txBuf, SENSORS_MESSAGE_LENGTH) == HAL_OK);
}

/*
 * callbacks.h
 *
 *  Created on: May 9, 2023
 *      Author: deslo
 */

#ifndef INC_CALLBACKS_H_
#define INC_CALLBACKS_H_


#include "encoder.h"
#include "hw_config.h"
#include "structs.h"
#include "jetson.h"


void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_pin);
//void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi);


#endif /* INC_CALLBACKS_H_ */

/*
 * callbacks.c
 *
 *  Created on: May 9, 2023
 *      Author: deslo
 */

#include "callbacks.h"

uint8_t recv = 1;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
	if (encoder_1.htim_abs->Instance == htim->Instance) {
		encoder_1.cl = HAL_TIM_ReadCapturedValue(encoder_1.htim_abs, TIM_CHANNEL_1);
		encoder_1.ch = HAL_TIM_ReadCapturedValue(encoder_1.htim_abs, TIM_CHANNEL_2);

		encoder_1.frequency = (float)(ENCODER_1_TIMER_CLOCK_FREQ) / (encoder_1.cl + 1);
		encoder_1.raw_duty_cycle = (float) 100 * encoder_1.ch / encoder_1.cl;
		Encoder_CalculateAbsolutePosition(&encoder_1);
		Encoder_SampleQuadraturePosition(&encoder_1);
		Encoder_CalculateQuadraturePosition(&encoder_1);
	}
//	if (encoder_1.htim_quad->Instance = htim->Instance) {
//	}
}

/* The current way the this will work is a default message will be sent each transaction depending on the address.
 * If the address is changed the next message sent will contain the wanted data unless a new address. */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_pin) {
	if (jetson.cs_pin == GPIO_pin) {
		Jetson_SendSensorData(&jetson, &sensors);
	}
}


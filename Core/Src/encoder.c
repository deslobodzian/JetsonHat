/*
 * encoder.c
 *
 *  Created on: May 8, 2023
 *      Author: deslo
 */

#include "encoder.h"

void Encoder_Init(Encoder_Struct *encoder, TIM_HandleTypeDef *htim_quad, TIM_HandleTypeDef *htim_abs, Encoder_Config *encoder_cfg) {
	encoder->htim_quad = htim_quad;
	encoder->htim_abs = htim_abs;

	encoder->cl = 0;
	encoder->ch = 0;

	encoder->frequency = 0;
	encoder->raw_duty_cycle = 0;
	encoder->raw_quadrature = 0;
	encoder->quad_prev_value = 0;
	encoder->quadrature_signed = 0;

	encoder->rotation_counts = 0;
	encoder->rotation_revolutions = 0;
	encoder->quadrature_radians = 0;

	encoder->absolute_position_radians = 0;

	encoder->cfg = encoder_cfg;
}

void Encoder_Start(Encoder_Struct *encoder) {
	/* Start the Quadrature Encoder Timer */
	HAL_TIM_Encoder_Start(encoder->htim_quad, TIM_CHANNEL_ALL);
	/* Start the Duty Cycle Encoder Timer */
	HAL_TIM_IC_Start_IT(encoder->htim_abs, TIM_CHANNEL_1); // primary channel - rising edge
	HAL_TIM_IC_Start(encoder->htim_abs, TIM_CHANNEL_2); // secondary channel - falling edge
}

void Encoder_Stop(Encoder_Struct *encoder) {
	HAL_TIM_Encoder_Stop(encoder->htim_quad, TIM_CHANNEL_ALL);
	HAL_TIM_IC_Stop(encoder->htim_abs, TIM_CHANNEL_1); // primary channel - rising edge
	HAL_TIM_IC_Stop(encoder->htim_abs, TIM_CHANNEL_2); // secondary channel - falling edge
}

void Encoder_Reset(Encoder_Struct *encoder) {
	encoder->raw_duty_cycle = 0;
	encoder->raw_quadrature = 0;
}

void Encoder_SampleQuadraturePosition(Encoder_Struct *encoder) {
	encoder->raw_quadrature = __HAL_TIM_GET_COUNTER(encoder->htim_quad);
	encoder->quadrature_signed = unwrap_encoder(encoder->raw_quadrature, &encoder->quad_prev_value);
}

void Encoder_CalculateAbsolutePosition(Encoder_Struct *encoder) {
	float duty_cycle_time = 1.0f + ((encoder->cfg->maximum_pulse * encoder->raw_duty_cycle) / 100.0f);
	encoder->absolute_position_radians = (2.0f * M_PI * duty_cycle_time) / encoder->cfg->output_period;
}
void Encoder_CalculateQuadraturePosition(Encoder_Struct *encoder) {
	encoder->rotation_revolutions = (float)encoder->quadrature_signed / (float)encoder->cfg->counts_per_revolution;
	encoder->quadrature_radians = encoder->rotation_revolutions * 2.0f * M_PI;
}

/* encode absolute position first, then the quadrature position */
void Encoder_EncodePosition(Encoder_Struct *encoder, uint8_t *data_buf, uint8_t data_position) {
	uint32_t* ptr1 = (uint32_t*)&encoder->absolute_position_radians;
	uint32_t* ptr2 = (uint32_t*)&encoder->quadrature_radians;

	// Encode float1 into spiBuffer
	data_buf[data_position] = (uint8_t)(*ptr1 >> 24);
	data_buf[data_position + 1] = (uint8_t)(*ptr1 >> 16);
	data_buf[data_position + 2] = (uint8_t)(*ptr1 >> 8);
	data_buf[data_position + 3] = (uint8_t)(*ptr1);

	// Encode float2 into spiBuffer
	data_buf[data_position + 4] = (uint8_t)(*ptr2 >> 24);
	data_buf[data_position + 5] = (uint8_t)(*ptr2 >> 16);
	data_buf[data_position + 6] = (uint8_t)(*ptr2 >> 8);
	data_buf[data_position + 7] = (uint8_t)(*ptr2);
}




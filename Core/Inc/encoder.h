/*
 * encoder.h
 *
 *  Created on: May 8, 2023
 *      Author: deslo
 */

#ifndef ENCODER_H
#define ENCODER_H


#include "stm32g4xx_hal.h"
#include "helpers.h"
#include <math.h>

typedef struct {
	uint32_t counts_per_revolution;

	uint16_t maximum_pulse;
	uint16_t output_period;
} Encoder_Config;

typedef struct {
	TIM_HandleTypeDef *htim_quad;
	TIM_HandleTypeDef *htim_abs;

	Encoder_Config *cfg;

	// call back stuff
	uint32_t cl;
	uint32_t ch;

	float frequency;
	float raw_duty_cycle;
	uint16_t raw_quadrature;
	int32_t quad_prev_value;
	int32_t quadrature_signed;

	float rotation_counts;
	float rotation_revolutions;
	float quadrature_radians;

	float absolute_position_radians;
} Encoder_Struct;

void Encoder_Init(Encoder_Struct *encoder, TIM_HandleTypeDef *htim_quad, TIM_HandleTypeDef *htim_abs, Encoder_Config *encoder_cfg);
void Encoder_Start(Encoder_Struct *encoder);
void Encoder_Stop(Encoder_Struct *encoder);
void Encoder_Reset(Encoder_Struct *encoder);
void Encoder_SampleQuadraturePosition(Encoder_Struct *encoder);
/* Calculate the absolute position and quadrature position from the configuration */
void Encoder_CalculateAbsolutePosition(Encoder_Struct *encoder);
void Encoder_CalculateQuadraturePosition(Encoder_Struct *encoder);
void Encoder_EncodePosition(Encoder_Struct *encoder, uint8_t *data_buf, uint8_t data_position);




#endif /* ENCODER_H */

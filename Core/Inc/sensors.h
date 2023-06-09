/*
 * sensors.h
 *
 *	This contains the struct for all the sensor data to be sent over SPI
 *  Created on: May 19, 2023
 *      Author: deslo
 */

#ifndef INC_SENSORS_H_
#define INC_SENSORS_H_

#include "encoder.h"


typedef struct {
	Encoder_Struct* encoder_1;
	Encoder_Struct* encoder_2;
	Encoder_Struct* encoder_3;
	Encoder_Struct* encoder_4;
} Sensors_Struct;


/* the sensor message for SPI will be formated in the order of the struct:
 * data_buf[0 -> 7] 		Absolute position and quadrature position, 8 bytes of data of encoder 1.
 * data_buf[8 -> 15]		Absolute position and quadrature position, 8 bytes of data of encoder 2.
 * data_buf[16 -> 23]		Absolute position and quadrature position, 8 bytes of data of encoder 3.
 * data_buf[24 -> 31]		Absolute position and quadrature position, 8 bytes of data of encoder 4.
 */
void Sensors_GenerateMessage(Sensors_Struct *sensors, uint8_t *data_buf);





#endif /* INC_SENSORS_H_ */

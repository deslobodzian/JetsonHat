/*
 * sensors.c
 *
 *  Created on: May 19, 2023
 *      Author: deslo
 */

#include "sensors.h"


/* only have one encode for now, so the message will be all encoder 1 */
void Sensors_GenerateMessage(Sensors_Struct *sensors, uint8_t *data_buf) {
	Encoder_EncodePosition(sensors->encoder_1, data_buf, 0);
	Encoder_EncodePosition(sensors->encoder_1, data_buf, 8);
	Encoder_EncodePosition(sensors->encoder_1, data_buf, 16);
	Encoder_EncodePosition(sensors->encoder_1, data_buf, 24);
}



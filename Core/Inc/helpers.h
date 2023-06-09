/*
 * helpers.h
 *
 *  Created on: May 16, 2023
 *      Author: deslo
 */

#ifndef INC_HELPERS_H_
#define INC_HELPERS_H_


#include <stdint.h>

#define ONE_PERIOD (INT32_MAX + 1)
#define HALF_PERIOD (UINT16_MAX / 2)


int32_t unwrap_encoder(uint16_t in, int32_t * prev);


#endif /* INC_HELPERS_H_ */

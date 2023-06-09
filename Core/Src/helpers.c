/*
 * helpers.c
 *
 *  Created on: May 16, 2023
 *      Author: deslo
 */

#include "helpers.h"


int32_t unwrap_encoder(uint16_t encoder_value, int32_t *prev_value) {
    const uint16_t half_period = UINT16_MAX / 2;

    int32_t current_value = encoder_value;

    // Calculate the difference between the current and previous values
    int32_t difference = current_value - *prev_value;

    // Handle wrap-around cases
    if (difference > half_period) {
        difference -= UINT16_MAX;
    } else if (difference < -half_period) {
        difference += UINT16_MAX;
    }

    // Update the previous value
    *prev_value += difference;

    // Adjust the unwrapped encoder value
    int32_t unwrapped_value = *prev_value;

    return unwrapped_value;
}

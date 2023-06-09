/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define NRST_Pin GPIO_PIN_10
#define NRST_GPIO_Port GPIOG
#define ENC_1_A_Pin GPIO_PIN_0
#define ENC_1_A_GPIO_Port GPIOC
#define ENC_1_B_Pin GPIO_PIN_1
#define ENC_1_B_GPIO_Port GPIOC
#define ENC_A_ABS_Pin GPIO_PIN_0
#define ENC_A_ABS_GPIO_Port GPIOA
#define ENC_2_B_Pin GPIO_PIN_1
#define ENC_2_B_GPIO_Port GPIOA
#define ENC_2_ABS_Pin GPIO_PIN_2
#define ENC_2_ABS_GPIO_Port GPIOA
#define NCS_GYRO_Pin GPIO_PIN_3
#define NCS_GYRO_GPIO_Port GPIOA
#define NCS_ACCEL_Pin GPIO_PIN_4
#define NCS_ACCEL_GPIO_Port GPIOA
#define INT_ACCEL_Pin GPIO_PIN_4
#define INT_ACCEL_GPIO_Port GPIOC
#define ENC_4_ABS_Pin GPIO_PIN_2
#define ENC_4_ABS_GPIO_Port GPIOB
#define NCS_JETSON_Pin GPIO_PIN_12
#define NCS_JETSON_GPIO_Port GPIOB
#define ENC_3_ABS_Pin GPIO_PIN_6
#define ENC_3_ABS_GPIO_Port GPIOC
#define INT_MAG_Pin GPIO_PIN_8
#define INT_MAG_GPIO_Port GPIOC
#define INT_MAG_EXTI_IRQn EXTI9_5_IRQn
#define TEST_LED_Pin GPIO_PIN_8
#define TEST_LED_GPIO_Port GPIOA
#define ENC_2_A_Pin GPIO_PIN_15
#define ENC_2_A_GPIO_Port GPIOA
#define NCS_MAG_Pin GPIO_PIN_2
#define NCS_MAG_GPIO_Port GPIOD
#define ENC_3_A_Pin GPIO_PIN_4
#define ENC_3_A_GPIO_Port GPIOB
#define ENC_3_B_Pin GPIO_PIN_5
#define ENC_3_B_GPIO_Port GPIOB
#define ENC_4_A_Pin GPIO_PIN_6
#define ENC_4_A_GPIO_Port GPIOB
#define ENC_4_B_Pin GPIO_PIN_7
#define ENC_4_B_GPIO_Port GPIOB
#define BOOT0_Pin GPIO_PIN_8
#define BOOT0_GPIO_Port GPIOB
#define DRDY_MAG_Pin GPIO_PIN_9
#define DRDY_MAG_GPIO_Port GPIOB
#define DRDY_MAG_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

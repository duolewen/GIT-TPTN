/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Bt_State_Pin GPIO_PIN_2
#define Bt_State_GPIO_Port GPIOE
#define BT_Key_Pin GPIO_PIN_3
#define BT_Key_GPIO_Port GPIOE
#define OUT_OT_Pin GPIO_PIN_4
#define OUT_OT_GPIO_Port GPIOE
#define INT1_Pin GPIO_PIN_5
#define INT1_GPIO_Port GPIOE
#define INT2_Pin GPIO_PIN_6
#define INT2_GPIO_Port GPIOE
#define SDA2_Pin GPIO_PIN_0
#define SDA2_GPIO_Port GPIOF
#define SCL2_Pin GPIO_PIN_1
#define SCL2_GPIO_Port GPIOF
#define PN1_Pin GPIO_PIN_2
#define PN1_GPIO_Port GPIOF
#define OUT8_Pin GPIO_PIN_3
#define OUT8_GPIO_Port GPIOF
#define LOW1_Pin GPIO_PIN_4
#define LOW1_GPIO_Port GPIOF
#define LOW2_Pin GPIO_PIN_5
#define LOW2_GPIO_Port GPIOF
#define OUT3_Pin GPIO_PIN_6
#define OUT3_GPIO_Port GPIOF
#define OUT4_Pin GPIO_PIN_7
#define OUT4_GPIO_Port GPIOF
#define OUT5_Pin GPIO_PIN_8
#define OUT5_GPIO_Port GPIOF
#define OUT6_Pin GPIO_PIN_9
#define OUT6_GPIO_Port GPIOF
#define OUT7_Pin GPIO_PIN_10
#define OUT7_GPIO_Port GPIOF
#define OUT9_Pin GPIO_PIN_0
#define OUT9_GPIO_Port GPIOC
#define OUT10_Pin GPIO_PIN_1
#define OUT10_GPIO_Port GPIOC
#define OUT11_Pin GPIO_PIN_2
#define OUT11_GPIO_Port GPIOC
#define OUT12_Pin GPIO_PIN_3
#define OUT12_GPIO_Port GPIOC
#define TX4_Pin GPIO_PIN_0
#define TX4_GPIO_Port GPIOA
#define RX4_Pin GPIO_PIN_1
#define RX4_GPIO_Port GPIOA
#define OUT1_Pin GPIO_PIN_2
#define OUT1_GPIO_Port GPIOA
#define OUT2_Pin GPIO_PIN_3
#define OUT2_GPIO_Port GPIOA
#define PN3_Pin GPIO_PIN_4
#define PN3_GPIO_Port GPIOA
#define PN4_Pin GPIO_PIN_5
#define PN4_GPIO_Port GPIOA
#define PN5_Pin GPIO_PIN_6
#define PN5_GPIO_Port GPIOA
#define PN6_Pin GPIO_PIN_7
#define PN6_GPIO_Port GPIOA
#define V_5_Pin GPIO_PIN_4
#define V_5_GPIO_Port GPIOC
#define V_6_Pin GPIO_PIN_5
#define V_6_GPIO_Port GPIOC
#define PWM5_Pin GPIO_PIN_0
#define PWM5_GPIO_Port GPIOB
#define PWM6_Pin GPIO_PIN_1
#define PWM6_GPIO_Port GPIOB
#define V_7_Pin GPIO_PIN_2
#define V_7_GPIO_Port GPIOB
#define V_8_Pin GPIO_PIN_11
#define V_8_GPIO_Port GPIOF
#define V_9_Pin GPIO_PIN_12
#define V_9_GPIO_Port GPIOF
#define V_10_Pin GPIO_PIN_13
#define V_10_GPIO_Port GPIOF
#define V_11_Pin GPIO_PIN_14
#define V_11_GPIO_Port GPIOF
#define V_12_Pin GPIO_PIN_15
#define V_12_GPIO_Port GPIOF
#define YPOWERO_Pin GPIO_PIN_0
#define YPOWERO_GPIO_Port GPIOG
#define UV_1_Pin GPIO_PIN_1
#define UV_1_GPIO_Port GPIOG
#define EN1_Pin GPIO_PIN_7
#define EN1_GPIO_Port GPIOE
#define DIR1_Pin GPIO_PIN_8
#define DIR1_GPIO_Port GPIOE
#define PUL1_Pin GPIO_PIN_9
#define PUL1_GPIO_Port GPIOE
#define EN2_Pin GPIO_PIN_10
#define EN2_GPIO_Port GPIOE
#define PUL2_Pin GPIO_PIN_11
#define PUL2_GPIO_Port GPIOE
#define DIR2_Pin GPIO_PIN_12
#define DIR2_GPIO_Port GPIOE
#define PUL3_Pin GPIO_PIN_13
#define PUL3_GPIO_Port GPIOE
#define DIR3_Pin GPIO_PIN_14
#define DIR3_GPIO_Port GPIOE
#define EN3_Pin GPIO_PIN_15
#define EN3_GPIO_Port GPIOE
#define TX3_Pin GPIO_PIN_10
#define TX3_GPIO_Port GPIOB
#define RX3_Pin GPIO_PIN_11
#define RX3_GPIO_Port GPIOB
#define SPI2_NSS_ADC_Pin GPIO_PIN_12
#define SPI2_NSS_ADC_GPIO_Port GPIOB
#define SPI2_NSS_DAC2_Pin GPIO_PIN_8
#define SPI2_NSS_DAC2_GPIO_Port GPIOD
#define SPI2_NSS_DAC1_Pin GPIO_PIN_9
#define SPI2_NSS_DAC1_GPIO_Port GPIOD
#define S_T1_Pin GPIO_PIN_10
#define S_T1_GPIO_Port GPIOD
#define S_T2_Pin GPIO_PIN_11
#define S_T2_GPIO_Port GPIOD
#define PWM1_Pin GPIO_PIN_12
#define PWM1_GPIO_Port GPIOD
#define PWM2_Pin GPIO_PIN_13
#define PWM2_GPIO_Port GPIOD
#define PWM3_Pin GPIO_PIN_14
#define PWM3_GPIO_Port GPIOD
#define PWM4_Pin GPIO_PIN_15
#define PWM4_GPIO_Port GPIOD
#define MOTO1_1_Pin GPIO_PIN_2
#define MOTO1_1_GPIO_Port GPIOG
#define MOTO1_2_Pin GPIO_PIN_3
#define MOTO1_2_GPIO_Port GPIOG
#define MOTO2_1_Pin GPIO_PIN_4
#define MOTO2_1_GPIO_Port GPIOG
#define MOTO2_2_Pin GPIO_PIN_5
#define MOTO2_2_GPIO_Port GPIOG
#define RLED_Pin GPIO_PIN_6
#define RLED_GPIO_Port GPIOG
#define GLED_Pin GPIO_PIN_7
#define GLED_GPIO_Port GPIOG
#define YLED_Pin GPIO_PIN_8
#define YLED_GPIO_Port GPIOG
#define TX6_Pin GPIO_PIN_6
#define TX6_GPIO_Port GPIOC
#define RX6_Pin GPIO_PIN_7
#define RX6_GPIO_Port GPIOC
#define YPOWERO1_Pin GPIO_PIN_8
#define YPOWERO1_GPIO_Port GPIOA
#define TX1_Pin GPIO_PIN_9
#define TX1_GPIO_Port GPIOA
#define RX1_Pin GPIO_PIN_10
#define RX1_GPIO_Port GPIOA
#define SDIO_CD_Pin GPIO_PIN_15
#define SDIO_CD_GPIO_Port GPIOA
#define IO_SCL1_Pin GPIO_PIN_0
#define IO_SCL1_GPIO_Port GPIOD
#define IO_SDA1_Pin GPIO_PIN_1
#define IO_SDA1_GPIO_Port GPIOD
#define IO_SCL2_Pin GPIO_PIN_3
#define IO_SCL2_GPIO_Port GPIOD
#define IO_SDA2_Pin GPIO_PIN_4
#define IO_SDA2_GPIO_Port GPIOD
#define TX2_Pin GPIO_PIN_5
#define TX2_GPIO_Port GPIOD
#define RX2_Pin GPIO_PIN_6
#define RX2_GPIO_Port GPIOD
#define V_4_Pin GPIO_PIN_10
#define V_4_GPIO_Port GPIOG
#define V_3_Pin GPIO_PIN_11
#define V_3_GPIO_Port GPIOG
#define V_2_Pin GPIO_PIN_12
#define V_2_GPIO_Port GPIOG
#define V_1_Pin GPIO_PIN_13
#define V_1_GPIO_Port GPIOG
#define SPI3_NSS6_Pin GPIO_PIN_14
#define SPI3_NSS6_GPIO_Port GPIOG
#define SPI3_NSS5_Pin GPIO_PIN_15
#define SPI3_NSS5_GPIO_Port GPIOG
#define SCL1_Pin GPIO_PIN_6
#define SCL1_GPIO_Port GPIOB
#define SDA1_Pin GPIO_PIN_7
#define SDA1_GPIO_Port GPIOB
#define SPI3_NSS4_Pin GPIO_PIN_8
#define SPI3_NSS4_GPIO_Port GPIOB
#define SPI3_NSS3_Pin GPIO_PIN_9
#define SPI3_NSS3_GPIO_Port GPIOB
#define SPI3_NSS2_Pin GPIO_PIN_0
#define SPI3_NSS2_GPIO_Port GPIOE
#define SPI3_NSS1_Pin GPIO_PIN_1
#define SPI3_NSS1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

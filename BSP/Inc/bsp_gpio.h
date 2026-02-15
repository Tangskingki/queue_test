/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    bsp_gpio.h
  * @brief   BSP GPIO abstraction (LED/KEY)
  ******************************************************************************
  */
/* USER CODE END Header */
#ifndef BSP_GPIO_H
#define BSP_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define BSP_LED_GPIO_Port GPIOC
#define BSP_LED_Pin GPIO_PIN_13

#define BSP_KEY_GPIO_Port GPIOB
#define BSP_KEY_Pin GPIO_PIN_14

void BSP_GPIO_Init(void);
void BSP_LED_On(void);
void BSP_LED_Off(void);
void BSP_LED_Toggle(void);
uint8_t BSP_KEY_Read(void);

#ifdef __cplusplus
}
#endif

#endif /* BSP_GPIO_H */

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    bsp_gpio.c
  * @brief   BSP GPIO abstraction (LED/KEY)
  ******************************************************************************
  */
/* USER CODE END Header */
#include "bsp_gpio.h"
#include "gpio.h"

void BSP_GPIO_Init(void)
{
  MX_GPIO_Init();
}

void BSP_LED_On(void)
{
  HAL_GPIO_WritePin(BSP_LED_GPIO_Port, BSP_LED_Pin, GPIO_PIN_SET);
}

void BSP_LED_Off(void)
{
  HAL_GPIO_WritePin(BSP_LED_GPIO_Port, BSP_LED_Pin, GPIO_PIN_RESET);
}

void BSP_LED_Toggle(void)
{
  HAL_GPIO_TogglePin(BSP_LED_GPIO_Port, BSP_LED_Pin);
}

uint8_t BSP_KEY_Read(void)
{
  return (HAL_GPIO_ReadPin(BSP_KEY_GPIO_Port, BSP_KEY_Pin) == GPIO_PIN_SET) ? 1U : 0U;
}

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_tasks.c
  * @brief   Application tasks
  ******************************************************************************
  */
/* USER CODE END Header */
#include "app_tasks.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "bsp_gpio.h"
#include "usart.h"
#include <string.h>

static void Uart_Print(const char *text)
{
  (void)HAL_UART_Transmit(&huart1, (uint8_t *)text, (uint16_t)strlen(text), 100);
}

void App_LedTask(void *argument)
{
  QueueHandle_t queue = (QueueHandle_t)argument;
  uint8_t event = 0U;

  Uart_Print("Tangs Kingki\r\n");

  for(;;)
  {
    if (xQueueReceive(queue, &event, portMAX_DELAY) == pdPASS)
    {
      if (event == 1U)
      {
        BSP_LED_Toggle();
        Uart_Print("Key press -> toggle LED\r\n");
      }
    }
  }
}

void App_KeyTask(void *argument)
{
  QueueHandle_t queue = (QueueHandle_t)argument;
  uint8_t lastState = 0U;

  for(;;)
  {
    uint8_t currentState = BSP_KEY_Read();

    if ((currentState == 1U) && (lastState == 0U))
    {
      uint8_t event = 1U;
      (void)xQueueSend(queue, &event, 0U);
    }

    lastState = currentState;
    vTaskDelay(pdMS_TO_TICKS(20));
  }
}

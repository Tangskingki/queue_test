/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "app_tasks.h"
#include "queue.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
static QueueHandle_t keyEventQueueHandle;

/* USER CODE END Variables */
/* Definitions for Task_Led */
osThreadId_t Task_LedHandle;
const osThreadAttr_t Task_Led_attributes = {
  .name = "Task_Led",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Task_Key */
osThreadId_t Task_KeyHandle;
const osThreadAttr_t Task_Key_attributes = {
  .name = "Task_Key",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Led_task(void *argument);
void Key_task(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  keyEventQueueHandle = xQueueCreate(8, sizeof(uint8_t));
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Task_Led */
  Task_LedHandle = osThreadNew(Led_task, NULL, &Task_Led_attributes);

  /* creation of Task_Key */
  Task_KeyHandle = osThreadNew(Key_task, NULL, &Task_Key_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Led_task */
/**
  * @brief  Function implementing the Task_Led thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Led_task */
void Led_task(void *argument)
{
  /* USER CODE BEGIN Led_task */
  App_LedTask((void *)keyEventQueueHandle);
  /* USER CODE END Led_task */
}

/* USER CODE BEGIN Header_Key_task */
/**
* @brief Function implementing the Task_Key thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Key_task */
void Key_task(void *argument)
{
  /* USER CODE BEGIN Key_task */
  App_KeyTask((void *)keyEventQueueHandle);
  /* USER CODE END Key_task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */


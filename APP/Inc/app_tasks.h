/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_tasks.h
  * @brief   Application tasks
  ******************************************************************************
  */
/* USER CODE END Header */
#ifndef APP_TASKS_H
#define APP_TASKS_H

#ifdef __cplusplus
extern "C" {
#endif

void App_LedTask(void *argument);
void App_KeyTask(void *argument);

#ifdef __cplusplus
}
#endif

#endif /* APP_TASKS_H */

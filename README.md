queue_test
基于 STM32F103 + FreeRTOS 的队列通信实验工程
项目简介
本项目是一个嵌入式实时操作系统应用示例，使用 STM32F103C8T6 单片机作为硬件平台，移植了 FreeRTOS 实时操作系统。核心功能是通过 FreeRTOS 的队列（Queue）机制，实现任务间的通信与同步，完成按键触发 LED 翻转等典型场景。
硬件平台
主控芯片：STM32F103C8T6（ARM Cortex-M3 内核）
开发环境：Keil MDK-ARM / STM32CubeMX
外设资源：
GPIO：按键输入、LED 输出
UART：串口打印调试信息
TIM：定时器作为 HAL 库时基
软件架构
操作系统：FreeRTOS V10.x
驱动库：STM32F1xx HAL 库
目录结构：
Core/：核心驱动与应用代码（main.c、中断处理等）
Drivers/：STM32 HAL 库与 CMSIS 内核文件
Middlewares/Third_Party/FreeRTOS/：FreeRTOS 源码
BSP/：板级支持包（GPIO、LCD、OLED、蜂鸣器等驱动）
APP/：应用任务代码（任务定义、队列操作等）
核心功能
FreeRTOS 任务创建：创建多个独立任务（如按键扫描任务、LED 控制任务）
队列通信：通过队列实现任务间数据传递（如按键事件通知）
外设驱动：GPIO、UART、LCD/OLED 等外设驱动封装
调试输出：通过串口打印任务调度、队列操作等调试信息
编译与下载
使用 STM32CubeMX 打开 queue_test.ioc 配置工程
生成 Keil MDK 工程文件
在 MDK 中编译代码，通过 J-Link / ST-Link 下载到开发板
上电后观察 LED 状态与串口输出，验证队列通信功能
学习价值
掌握 FreeRTOS 任务管理、队列通信的核心原理
熟悉 STM32 HAL 库的使用方法
理解嵌入式实时系统的开发流程与调试技巧

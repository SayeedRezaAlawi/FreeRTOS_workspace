/*
 * mainCpp.cpp
 *
 *  Created on: Feb 6, 2023
 *      Author: Reza
 */

#include "mainCpp.h"
#include "ledblink.h"


#include <stdio.h>

#define DWT_CTRL    (*(volatile uint32_t*)0xE0001000)


static void led_green_handler (void* parameters);
static void led_red_handler (void* parameters);
static void led_blue_handler (void* parameters);
//static void led_red2_handler (void* parameters);
//static void button_handler (void* parameters);
//void led_task(void* parameters);
void button_interrupt_handler(void);

TaskHandle_t ledG_task_handle;
TaskHandle_t ledR_task_handle;
TaskHandle_t ledB_task_handle;
//TaskHandle_t ledR2_task_handle;
//TaskHandle_t btn_task_handle;

xTimerHandle timer;

TaskHandle_t volatile next_task_handle = NULL;

void timer_callback(xTimerHandle xTimer);

int mainCpp(void)
{
	BaseType_t status;
//
//	TIM1->CCR1 = 50;
//	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

	DWT_CTRL |= ( 1 << 0);
	SEGGER_UART_init(500000);
	SEGGER_SYSVIEW_Conf();
//	SEGGER_SYSVIEW_Start();

	status = xTaskCreate(led_green_handler, "LED_grean_task", 200, NULL, 3, &ledG_task_handle);

	configASSERT(status == pdPASS);


	next_task_handle = ledG_task_handle;

	status = xTaskCreate(led_red_handler, "LED_red_task", 200, NULL, 2, &ledR_task_handle);

	configASSERT(status == pdPASS);

	status = xTaskCreate(led_blue_handler, "LED_blue_task", 200, NULL, 1, &ledB_task_handle);

	configASSERT(status == pdPASS);

	timer = xTimerCreate("timer", pdMS_TO_TICKS(1000), pdTRUE, NULL, timer_callback);
	xTimerStart(timer,portMAX_DELAY);

//	status = xTaskCreate(led_red2_handler, "RED2_blue_task", 200, NULL, 1, &ledR2_task_handle);

//	configASSERT(status == pdPASS);

//	status = xTaskCreate(button_handler, "Button_task", 200, NULL, 4, &btn_task_handle);

//	configASSERT(status == pdPASS);

	vTaskStartScheduler();

	while(1)
	{

	}

}

static void led_green_handler (void* parameters)
{
	BaseType_t status;

	while(1)
	{
		SEGGER_SYSVIEW_PrintfTarget("Toggling Green Led");
		HAL_GPIO_TogglePin(GPIOB, LED_GREEN_Pin);

		status = xTaskNotifyWait(0,0,NULL, pdMS_TO_TICKS(1000));
		if(status == pdTRUE)
		{
			portENTER_CRITICAL();
			next_task_handle = ledR_task_handle;
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_SET);
			SEGGER_SYSVIEW_PrintfTarget("Delete GREEN LED");
			portEXIT_CRITICAL();
			vTaskDelete(NULL);
		}
	}
}

static void led_red_handler (void* parameters)
{
	BaseType_t status;

	while(1)
	{
		SEGGER_SYSVIEW_PrintfTarget("Toggling Red Led");
		HAL_GPIO_TogglePin(GPIOB, LED_RED_Pin);

		status = xTaskNotifyWait(0,0,NULL, pdMS_TO_TICKS(800));
		if(status == pdTRUE)
		{
			portENTER_CRITICAL();
			next_task_handle = ledB_task_handle;
			HAL_GPIO_WritePin(GPIOB, LED_RED_Pin, GPIO_PIN_SET);
			SEGGER_SYSVIEW_PrintfTarget("Delete RED LED");
			portEXIT_CRITICAL();
			vTaskDelete(NULL);
		}
	}
}


static void led_blue_handler (void* parameters)
{
	BaseType_t status;

	while(1)
	{
		SEGGER_SYSVIEW_PrintfTarget("Toggling Blue Led");
		HAL_GPIO_TogglePin(GPIOB, LED_BLUE_Pin);

		status = xTaskNotifyWait(0,0,NULL, pdMS_TO_TICKS(400));
		if(status == pdTRUE)
		{
			portENTER_CRITICAL();
			next_task_handle = NULL;
			HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_SET);
			SEGGER_SYSVIEW_PrintfTarget("Delete BLUE LED");
			portEXIT_CRITICAL();
			vTaskDelete(NULL);
		}
	}
}

//static void button_handler (void* parameters)
//{
//	uint8_t btn_read = 0;
//	uint8_t prev_read = 0;
//
//	while(1)
//	{
//		btn_read = HAL_GPIO_ReadPin(GPIOI, BTN_Pin);
//
//		if(btn_read)
//		{
//			if(! prev_read)
//			{
//				xTaskNotify(next_task_handle, 0 ,eNoAction);
//			}
//		}
//		prev_read = btn_read;
//		vTaskDelay(pdMS_TO_TICKS(10));
//
//		SEGGER_SYSVIEW_PrintfTarget("Button Task");
//	}
//}



//static void led_red2_handler (void* parameters)
//{
//
//	BaseType_t status;
//
//	while(1)
//	{
//		SEGGER_SYSVIEW_PrintfTarget("Toggling Red Led");
//		HAL_GPIO_TogglePin(GPIOB, LED_RED_Pin);
//
//		status = xTaskNotifyWait(0,0,NULL, pdMS_TO_TICKS(800));
//		if(status == pdTRUE)
//		{
//			vTaskSuspendAll();
//			next_task_handle = ledB_task_handle;
//			xTaskResumeAll();
//			HAL_GPIO_WritePin(GPIOB, LED_RED_Pin, GPIO_PIN_SET);
//			SEGGER_SYSVIEW_PrintfTarget("Delete RED LED");
//			vTaskDelete(NULL);
//		}
//
//		//Blocking delay function, which consume the CPU resources
////		vTaskDelay(pdMS_TO_TICKS(800));
//	}
//}


void button_interrupt_handler(void)
{
	BaseType_t pxHigherPriorityTaskwWoken;

	//Variable that holds states of task which receive notification
	pxHigherPriorityTaskwWoken = pdFALSE;

	traceISR_ENTER();
	xTaskNotifyFromISR(next_task_handle, 0, eNoAction, &pxHigherPriorityTaskwWoken);

	// once the ISR exits, the below macro makes higher priority task which got unblocked to resume on the CPU
	portYIELD_FROM_ISR(pxHigherPriorityTaskwWoken);

	traceISR_EXIT();
}


//void EXTI15_10_IRQHandler(void)
//{
//  /* USER CODE BEGIN EXTI15_10_IRQn 0 */
//	button_interrupt_handler();
//  /* USER CODE END EXTI15_10_IRQn 0 */
//  HAL_GPIO_EXTI_IRQHandler(BTN_Pin);
//  /* USER CODE BEGIN EXTI15_10_IRQn 1 */
//
//  /* USER CODE END EXTI15_10_IRQn 1 */
//}


void timer_callback(xTimerHandle xTimer)
{
	static int timerPeriod =0;

	HAL_GPIO_TogglePin(GPIOI, USR_LED_Pin);
	if(timerPeriod < 20)
	{
		xTimerChangePeriod(timer, pdMS_TO_TICKS(100), portMAX_DELAY);
		timerPeriod++;
	}else if (timerPeriod < 25)
	{
		xTimerChangePeriod(timer, pdMS_TO_TICKS(500), portMAX_DELAY);
		timerPeriod++;
	}else if (timerPeriod < 30)
	{
		xTimerChangePeriod(timer, pdMS_TO_TICKS(1000), portMAX_DELAY);
		timerPeriod++;
	}else
	{
		timerPeriod = 0;
	}

}

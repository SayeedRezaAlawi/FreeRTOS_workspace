/*
 * led_effect.c
 *
 *  Created on: Jan 31, 2023
 *      Author: Reza
 */

#include "main.h"


void led_effect_stop(void)
{
	for(int i=0; i < 4; i++)
	{
		xTimerStop(handle_led_timer[i], portMAX_DELAY);
	}

}


void led_effect(uint8_t n)
{
	led_effect_stop();
	xTimerStart(handle_led_timer[n-1], portMAX_DELAY);
}


void turn_off_all_leds(void)
{
	HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin, GPIO_PIN_RESET);
}

void turn_on_all_leds(void)
{
	HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, LED_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin, GPIO_PIN_SET);
}

void turn_on_odd_leds(void)
{
	HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin, GPIO_PIN_RESET);
}

void turn_on_even_leds(void)
{
	HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin, GPIO_PIN_SET);
}

void LED_control(int value)
{
	for(int i=0; i < 4; i++)
	{
		switch(i)
		{
		case 0:
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, ((value >> i) & 0x1) );
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, LED_RED_Pin, ((value >> i) & 0x1) );
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, ((value >> i) & 0x1) );
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin, ((value >> i) & 0x1) );
			break;
		}
	}

}

void led_effect1(void)
{
	static int flag = 1;
	(flag ^= 1) ? turn_off_all_leds() : turn_on_all_leds();
}

void led_effect2(void)
{
	static int flag = 1;
	(flag ^= 1) ? turn_on_even_leds() : turn_on_odd_leds();
}

void led_effect3(void)
{
	static int i=0;
	LED_control(0x1 << (i++ % 4));
}

void led_effect4(void)
{
	static int i=0;
	LED_control(0x08 >> (i++ % 4));
}

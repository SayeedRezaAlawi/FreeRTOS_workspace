/*
 * CFlashlightLed.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#include "CFlashlightLed.h"

void CFlashlightLed::setBrightness(uint8_t brightness)
{
	switch(brightness)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, LED_RED_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin, GPIO_PIN_SET);
			break;
	}
}

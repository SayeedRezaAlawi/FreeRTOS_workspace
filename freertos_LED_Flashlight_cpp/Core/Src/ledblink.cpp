/*
 * ledBlink.cpp
 *
 *  Created on: Feb 6, 2023
 *      Author: Reza
 */

#include "ledblink.h"

void ledBlink::ledToggle()
{
	HAL_GPIO_TogglePin(GPIOI, USR_LED_Pin);
}

void ledBlink::ledToggle(uint8_t pinNumber)
{
	if(pinNumber == 1)
	{
		HAL_GPIO_TogglePin(GPIOB, LED_GREEN_Pin);
	}
}

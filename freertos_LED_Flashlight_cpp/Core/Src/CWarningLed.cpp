/*
 * CWarningLed.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#include "CWarningLed.h"

void CWarningLed::on()
{
	HAL_GPIO_WritePin(GPIOI, USR_LED_Pin, GPIO_PIN_SET);
}


void CWarningLed::off()
{
	HAL_GPIO_WritePin(GPIOI, USR_LED_Pin, GPIO_PIN_RESET);
}

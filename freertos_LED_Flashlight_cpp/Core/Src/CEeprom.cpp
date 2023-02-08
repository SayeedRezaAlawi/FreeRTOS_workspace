/*
 * CEeprom.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#include "CEeprom.h"

void CEeprom::store(uint8_t value)
{
	m_vlaue = value;
}



uint8_t CEeprom::retrieve()
{
	return m_vlaue;
}

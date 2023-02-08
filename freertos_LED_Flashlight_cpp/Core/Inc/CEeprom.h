/*
 * CEeprom.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#ifndef INC_CEEPROM_H_
#define INC_CEEPROM_H_

#include "main.h"

class CEeprom
{
	private:
		uint8_t m_vlaue;
	public:
		void store(uint8_t value);
		uint8_t retrieve();
};

#endif /* INC_CEEPROM_H_ */

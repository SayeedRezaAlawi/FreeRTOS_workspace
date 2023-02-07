/*
 * ledblink.h
 *
 *  Created on: Feb 6, 2023
 *      Author: Reza
 */

#ifndef INC_LEDBLINK_HPP_
#define INC_LEDBLINK_HPP_

#include "main.h"

#ifdef __cplusplus
extern "C"
{
#endif

class ledBlink
{

public:
	void ledToggle();
	void ledToggle(uint8_t pinNumber);
};

#ifdef __cplusplus
}
#endif //extern "C"

#endif /* INC_LEDBLINK_HPP_ */

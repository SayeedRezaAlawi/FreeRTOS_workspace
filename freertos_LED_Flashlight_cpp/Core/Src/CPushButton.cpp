/*
 * CPushButton.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#include "CPushButton.h"


void CPushButton::setEventQueue(CEventQueue& eventQueue)
{
	m_eventQueue = &eventQueue;
}


void CPushButton::addEvent(Event event)
{
	m_eventQueue->addEvent(event);
}


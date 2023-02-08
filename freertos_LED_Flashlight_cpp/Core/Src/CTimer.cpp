/*
 * CTimer.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#include "CTimer.h"


void CTimer::setEventQueue(CEventQueue& eventQueue)
{
	m_eventQueue = &eventQueue;
}


void CTimer::addEvent(Event event)
{
	m_eventQueue->addEvent(event);
}

void CTimer::setWaitTime(uint16_t millis)
{
	xTimerChangePeriod(timer, pdMS_TO_TICKS(millis), portMAX_DELAY);
}

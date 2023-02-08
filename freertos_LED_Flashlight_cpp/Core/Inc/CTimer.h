/*
 * CTimer.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#ifndef CTIMER_H_
#define CTIMER_H_

#include "CEventQueue.h"
#include "main.h"

class CTimer
{
	private:
		CEventQueue* m_eventQueue;
	public:
		void setEventQueue(CEventQueue& eventQueue);
		void addEvent(Event event);
		void setWaitTime(uint16_t millis);

};

#endif /* CTIMER_H_ */

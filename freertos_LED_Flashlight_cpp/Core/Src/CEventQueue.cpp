/*
 * CEventQueue.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#include "CEventQueue.h"


Event CEventQueue::nextEvent()
{
	Event event;
	if(!queue.empty())
	{
		event=queue.back();
		queue.pop_back();
	}
	return event;
}


void CEventQueue::addEvent(Event event)
{
	queue.push_back(event);
}

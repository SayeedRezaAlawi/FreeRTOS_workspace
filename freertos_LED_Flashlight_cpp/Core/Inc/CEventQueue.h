/*
 * CEventQueue.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Reza
 */

#ifndef INC_CEVENTQUEUE_H_
#define INC_CEVENTQUEUE_H_

#include "Event.h"
#include <list>

class CEventQueue
{
	private:
		std::list<Event> queue;

	public:
		Event nextEvent();
		void addEvent(Event event);
};

#endif /* INC_CEVENTQUEUE_H_ */

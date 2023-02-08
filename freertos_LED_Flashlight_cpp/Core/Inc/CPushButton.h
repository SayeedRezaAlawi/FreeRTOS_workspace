/*
 * CPushButton.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#ifndef INC_CPUSHBUTTON_H_
#define INC_CPUSHBUTTON_H_

#include "CEventQueue.h"

class CPushButton
{
	private:
		CEventQueue* m_eventQueue;
	public:
		void setEventQueue(CEventQueue& eventQueue);
		void addEvent(Event event);

};

#endif /* INC_CPUSHBUTTON_H_ */

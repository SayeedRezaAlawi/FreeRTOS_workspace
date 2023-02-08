/*
 * CController.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#ifndef INC_CCONTROLLER_H_
#define INC_CCONTROLLER_H_

#include "CPushButton.h"
#include "CTimer.h"
#include "CFlashlightLed.h"
#include "CWarningLed.h"
#include "CVoltageMeter.h"
#include "CEeprom.h"
#include "CEventQueue.h"

class CController
{
	protected:
		CPushButton* m_mode;
		CTimer* m_tmr;
		CFlashlightLed* m_light;
		CWarningLed* m_hbu;
		CVoltageMeter* m_bat;
	protected:
		CEventQueue m_evtQueue;
		CEeprom* m_eeprom;

		CController(CPushButton* pushBtn, CTimer* timer, CFlashlightLed* light,
		CWarningLed* hbu, CVoltageMeter* bat, CEeprom* eeprom);
	public:
		~CController();
		virtual void run() = 0;
};

#endif /* INC_CCONTROLLER_H_ */

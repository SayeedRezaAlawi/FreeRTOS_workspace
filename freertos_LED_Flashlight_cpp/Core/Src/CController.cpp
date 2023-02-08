/*
 * CController.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#include "CController.h"


CController::CController(CPushButton* pushBtn, CTimer* timer, CFlashlightLed* light,
		CWarningLed* hbu, CVoltageMeter* bat, CEeprom* eeprom)
{
	m_mode = pushBtn;
	m_mode->setEventQueue(m_evtQueue);

	m_tmr = timer;
	m_tmr->setEventQueue(m_evtQueue);

	m_light = light;
	m_hbu = hbu;
	m_bat = bat;
	m_eeprom = eeprom;
}

CController::~CController() {
}

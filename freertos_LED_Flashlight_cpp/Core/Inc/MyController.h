/*
 * MyController.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#ifndef MYCONTROLLER_H_
#define MYCONTROLLER_H_

#include "CController.h"


#define HBU_ON 					(m_hbu->on())
#define HBU_OFF 				(m_hbu->off())
#define TMR(X) 					(m_tmr->setWaitTime(X))
#define FLB(X) 					(m_light->setBrightness(X))
#define EES(X) 					(m_eeprom->store(X))
#define EER 					(m_eeprom->retrieve())
#define BAT 					(m_bat->getVoltage())

class MyController: public CController
{
public:
	MyController(CPushButton* pushBtn, CTimer* timer, CFlashlightLed* light,
			CWarningLed* hbu, CVoltageMeter* bat, CEeprom* eeprom);
	void run();
};

#endif /* MYCONTROLLER_H_ */

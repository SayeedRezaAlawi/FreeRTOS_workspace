
/*
 * MyController.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Reza
 */

#include "MyController.h"

MyController::MyController(CPushButton *pushBtn, CTimer *timer,
		CFlashlightLed *light, CWarningLed *hbu, CVoltageMeter *bat,
		CEeprom *eeprom): CController(pushBtn, timer, light, hbu, bat, eeprom)
{
}

void MyController::run()
{
	enum State{
		Idle,
		ButtonPushed,
		StrobeOff,
		StrobeOn,
		Warn,
	};

	State state = Idle;

	while(true)
	{
		Event event = m_evtQueue.nextEvent();

		switch(state){

		case Idle:
			if(event == BPushed){
				TMR(500);
				state = ButtonPushed;
			}
			break;
		case ButtonPushed:
			if(event == TmrEXP){
				if(EER == 3 && BAT < 6){
					HBU_ON;
					state = Warn;
				}else{
					EES(EER % 4 + 1);
					FLB(EER);
					state = Idle;
				}
			}
			if(event == BPushed){
				TMR(100);
				FLB(0);
				state = StrobeOff;
			}
			break;
		case Warn:
			if(event == BPushed){
				EES(1);
				FLB(EER);
				HBU_OFF;
				state = Idle;
			}
			break;
		case StrobeOff:
			if(event == BPushed){
				FLB(EER);
				TMR(0);
				state = Idle;
			}
			if(event == TmrEXP){
				FLB(EER);
				TMR(100);
				state = StrobeOn;
			}
			break;
		case StrobeOn:
			if(event == BPushed){
				TMR(0);
				state = Idle;
			}
			if(event == TmrEXP){
				FLB(0);
				TMR(100);
				state = StrobeOff;
			}
			break;
		}
	}
}

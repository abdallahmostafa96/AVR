/*
 * Switch_Interface.h
 *
 *  Created on: 27 Feb 2023
 *      Author: abdallah
 */
#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_
#include "Switch_Private.h"
#include "Switch_Configuration.h"

SwitchErrState  SW_SwitchErrStateGetState(Switch_Info * Switch ,RS_info * Result);
SwitchErrState  SW_ErrStateSetState(Switch_Info * Switch);
#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */

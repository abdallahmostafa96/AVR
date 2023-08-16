/*
 * Switch_Private.h
 *
 *  Created on: 27 Feb 2023
 *      Author: abdallah
 */
#ifndef HAL_SWITCH_SWITCH_PRIVATE_H_
#define HAL_SWITCH_SWITCH_PRIVATE_H_


typedef enum
{
	NOSWITCHERRPR,
	ERRORSWITCH
}SwitchErrState;

typedef enum
{
	PressedPullUp,
	NotPressedPullUp,
	NotPressedPullDown=0,
	PressedPullDown,


}SwitchState;

typedef enum
{
	InternalPullUp,
	ExternalPullUp,
	ExternalPullDown
}SwitchConnectionType;


#endif /* HAL_SWITCH_SWITCH_PRIVATE_H_ */

/*
 * Switch_Configuration.h
 *
 *  Created on: 27 Feb 2023
 *      Author: abdallah
 */
#ifndef HAL_SWITCH_SWITCH_CONFIGURATION_H_
#define HAL_SWITCH_SWITCH_CONFIGURATION_H_
#include "../../MCAL/DIO/DIO_Private.h"
typedef struct
{
	DIO_GroupNumber  SW_Group ;
	DIO_PinNumber    SW_Pin ;
	SwitchConnectionType   ConnectionType ;
}Switch_Info ;

typedef struct
{
	DIO_GroupNumber  RS_Group ;
	DIO_PinNumber    RS_Pin ;

}RS_info ;

#endif /* HAL_SWITCH_SWITCH_CONFIGURATION_H_ */

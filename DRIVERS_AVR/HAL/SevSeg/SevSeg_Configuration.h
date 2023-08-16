/*
 * SevSeg_Configuration.h
 *
 *  Created on: 28 Feb 2023
 *      Author: abdallah
 */
#ifndef HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
#define HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
typedef struct
{
	SevSeg_Type SevSeg_Type       ;
	DIO_GroupNumber SevSeg_Group      ;
	DIO_GroupNumber SevSeg_EnablePort ;
	DIO_PinNumber SevSeg_EnablePin  ;
}SevSeg_info;


#endif /* HAL_SEVSEG_SEVSEG_CONFIGURATION_H_ */

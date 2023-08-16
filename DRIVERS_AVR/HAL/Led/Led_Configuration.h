/*
 * Led_Configuration.h
 *
 *  Created on: 25 Feb 2023
 *      Author: abdallah
 */
#ifndef HAL_LED_LED_CONFIGURATION_H_
#define HAL_LED_LED_CONFIGURATION_H_

typedef struct
{
DIO_GroupNumber        Led_Group ;
DIO_PinNumber          Led_Pin ;
Led_ConnectionType     ConnectionType ;
}Led_info;


#endif /* HAL_LED_LED_CONFIGURATION_H_ */

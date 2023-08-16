/*
 * Led_Private.h
 *
 *  Created on: 25 Feb 2023
 *      Author: abdallah
 */
#ifndef HAL_LED_LED_PRIVATE_H_
#define HAL_LED_LED_PRIVATE_H_

typedef enum
{
	on,
	off
}LedErrState;

typedef enum {
	Errorcon,
	Source_Connection ,
	Sink_Connection

}Led_ConnectionType;



#endif /* HAL_LED_LED_PRIVATE_H_ */

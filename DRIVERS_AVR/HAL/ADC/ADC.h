/*
 * ADC.h
 *
 *  Created on: 1 Mar 2023
 *      Author: abdallah
 */
 #ifndef ADC_H_
#define ADC_H_

#include "std_macros.h"

void ADC_init(void);

uint16_t ADC_read(void);

#endif /* ADC_H_ */
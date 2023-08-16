/*
 * SPI.h
 *
 *  Created on: 10 Mar 2023
 *      Author: abdallah
 */
#ifndef SPI_H_
#define SPI_H_

#include "std_macros.h"


#define SS   PB4
#define MOSI PB5
#define MISO PB6
#define SCK  PB7

void SPI_init_master(void);
void SPI_init_slave(void);

void SPI_master_output(uint8_t data);
u8 SPI_slave_input(void);


u8 SPI_RX_TX(uint8_t data);




#endif /* SPI_H_ */
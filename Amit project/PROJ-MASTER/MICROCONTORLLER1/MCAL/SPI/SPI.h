/*
 * SPI.h
 *
 *  Created on: Aug 21, 2021
 *      Author: User
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../../../MICROCONTORLLER1/MCAL/DIO/DIO.h"
#include "../../../MICROCONTORLLER1/MCAL/SPI/SPI_CONFIG.h"

void SPI_MASTER_TRANSMIT(char cData);
char SPI_MASTER_RECEIVE(void);
void SPI_SLAVE_TRANSMIT(char cData);
char SPI_SLAVE_RECEIVE(void);
void CALLBACK_INTERRUPT_SPI(void(*p0)(void));
void SPI_INIT();

#endif /* MCAL_SPI_SPI_H_ */

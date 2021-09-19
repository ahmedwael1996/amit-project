/*
 * SPI.c
 *
 *  Created on: Aug 21, 2021
 *      Author: User
 */


#include "../../../MICROCONTORLLER1/MCAL/SPI/SPI.h"

#include <avr/io.h>

void (*INTERRUPT_SPI_CALL_BACK)(void);


void SPI_MASTER_TRANSMIT(char cData)
{

SPDR = cData;

while(!(SPSR & (1<<SPIF)))
;
}


char SPI_SLAVE_RECEIVE(void)
{

while(!(SPSR & (1<<SPIF)))
;

return SPDR;
}


void SPI_INIT(){
	if(SPI_STATUS == ENABLE){
		SET_BIT(SPCR,SPE);



		if(SPI_FUNCTIONALLITY == SPI_SAMPLE){
			CLEAR_BIT(SPCR,CPHA);
		}
		else if(SPI_FUNCTIONALLITY == SPI_SETUP){
			SET_BIT(SPCR,CPHA);
		}



		if (SPI_FREQ_MODE == SPI_FREQ_4) {
			CLEAR_BIT(SPCR, SPR0);
			CLEAR_BIT(SPCR, SPR1);
			CLEAR_BIT(SPSR, SPI2X);
		}
		else if (SPI_FREQ_MODE == SPI_FREQ_16) {
			SET_BIT(SPCR, SPR0);
			CLEAR_BIT(SPCR, SPR1);
			CLEAR_BIT(SPSR, SPI2X);
		}
		else if (SPI_FREQ_MODE == SPI_FREQ_64) {
			CLEAR_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			CLEAR_BIT(SPSR, SPI2X);
		}
		else if (SPI_FREQ_MODE == SPI_FREQ_128) {
			SET_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			CLEAR_BIT(SPSR, SPI2X);
		}
		else if (SPI_FREQ_MODE == SPI_FREQ_2_DOUBLE_SPEED) {
			CLEAR_BIT(SPCR, SPR0);
			CLEAR_BIT(SPCR, SPR1);
			SET_BIT(SPSR, SPI2X);
		}
		else if (SPI_FREQ_MODE == SPI_FREQ_8_DOUBLE_SPEED) {
			SET_BIT(SPCR, SPR0);
			CLEAR_BIT(SPCR, SPR1);
			SET_BIT(SPSR, SPI2X);
		}
		else if (SPI_FREQ_MODE == SPI_FREQ_32_DOUBLE_SPEED) {
			CLEAR_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			SET_BIT(SPSR, SPI2X);
		}
		else if (SPI_FREQ_MODE == SPI_FREQ_64_DOUBLE_SPEED) {
			SET_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			SET_BIT(SPSR, SPI2X);
		}


		if(SPI_DATA_ORDER == MSB){
			CLEAR_BIT(SPCR,DORD);
		}
		else if(SPI_DATA_ORDER == LSB){
			SET_BIT(SPCR,DORD);
		}


		if(SPI_INTTERUPT_MODE == ENABLE){
			SET_BIT(SPCR,SPIE);
		}
		else if(SPI_INTTERUPT_MODE == DISABLE){
			CLEAR_BIT(SPCR,SPIE);
		}


		if(SPI_MODE == SPI_MASTER_MODE){
			DDRB |= (1<<5)|(1<<7);
			SET_BIT(SPCR,MSTR);

		}
		else if(SPI_MODE == SPI_SLAVE_MODE){
			DDRB |= (1<<6);
			CLEAR_BIT(SPCR,MSTR);
		}




	}
	else if(SPI_STATUS == DISABLE){

	}
}



void CALLBACK_INTERRUPT_SPI(void(*p0)(void)){

	INTERRUPT_SPI_CALL_BACK=p0;
}

ISR(SPI_STC_vect){
	INTERRUPT_SPI_CALL_BACK();
}

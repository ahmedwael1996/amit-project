/*
 * USART.c
 *
 *  Created on: Aug 22, 2021
 *      Author: User
 */

#include "../../../MICROCONTORLLER1/MCAL/USART/USART.h"

void (*INTERRUPT_USART_TX_CALL_BACK)(void);
void (*INTERRUPT_USART_RX_CALL_BACK)(void);

void USART_Transmit( uint8 data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) )
;
/* Put data into buffer, sends the data */
UDR = data;
}
void USART_Transmit_9BIT( unsigned int data ){
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)))
;
/* Copy 9th bit to TXB8 */
UCSRB &= ~(1<<TXB8);
if ( data & 0x0100 )
UCSRB |= (1<<TXB8);
/* Put data into buffer, sends the data */
UDR = data;
}
uint8 USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) )
;
/* Get and return received data from buffer */
return UDR;
}
unsigned int USART_Receive_9BIT( void )
{
uint8 status, resh, resl;
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) )
;
/* Get status and 9th bit, then data */
/* from buffer */
status = UCSRA;
resh = UCSRB;
resl = UDR;
/* If error, return -1 */
if ( (status & (1<<FE))|(1<<DOR)|(1<<PE) )
return -1;
/* Filter the 9th bit, then return */
resh = (resh >> 1) & 0x01;
return ((resh << 8) | resl);
}

void USART_INIT(){
	if(USART_TRANSMIT_MODE == ENABLE){
		SET_BIT(UCSRB, TXEN);
	}
	else if(USART_TRANSMIT_MODE == DISABLE){
		CLEAR_BIT(UCSRB, TXEN);
	}
	if(USART_RECEIVE_MODE == ENABLE){
		SET_BIT(UCSRB, RXEN);
	}
	else if(USART_RECEIVE_MODE == DISABLE){
		CLEAR_BIT(UCSRB, RXEN);
	}


	if(UART_BIT_SETTING == USART_BIT_5_MODE){
		CLEAR_BIT(UCSRB,UCSZ2);
		UCSRC |= (((1 << URSEL) & ~(1 << UCSZ1)) & ~(1 << UCSZ0));
	}
	else if(UART_BIT_SETTING == USART_BIT_6_MODE){
		CLEAR_BIT(UCSRB,UCSZ2);
		UCSRC |= (((1 << URSEL) & ~(1 << UCSZ1)) | (1 << UCSZ0));
	}
	else if(UART_BIT_SETTING == USART_BIT_7_MODE){
		CLEAR_BIT(UCSRB,UCSZ2);
		UCSRC |= (((1 << URSEL) | (1 << UCSZ1)) & ~(1 << UCSZ0));
	}
	else if(UART_BIT_SETTING == USART_BIT_8_MODE){
		CLEAR_BIT(UCSRB,UCSZ2);
		UCSRC |= (((1 << URSEL) | (1 << UCSZ1)) | (1 << UCSZ0));
	}
	else if(UART_BIT_SETTING == USART_BIT_9_MODE){
		SET_BIT(UCSRB,UCSZ2);
		UCSRC |= (((1 << URSEL) | (1 << UCSZ1)) | (1 << UCSZ0));
	}



	if(USART_ASYNCHRONOUS_SPEED == USART_ASYNCHRONOUS_NORMAL_SPEED){
		CLEAR_BIT(UCSRA, U2X);
	}
	else if(USART_ASYNCHRONOUS_SPEED == USART_ASYNCHRONOUS_DOUBLE_SPEED){
		SET_BIT(UCSRA,U2X);
	}


	if(USART_PARITY_MODE == USART_PARITY_DISABELED){
		UCSRC |= ((1 << URSEL) & ~(1 << UPM1) & ~(1 << UPM0));
	}
	else if(USART_PARITY_MODE == USART_PARITY_REVERSED){
		UCSRC |= (((1 << URSEL) & ~(1 << UPM1)) | (1 << UPM0));
	}
	else if(USART_PARITY_MODE == USART_EVEN_PARITY){
		UCSRC |= ((1 << URSEL) | ((1 << UPM1) & ~(1 << UPM0)));
	}
	else if(USART_PARITY_MODE == USART_ODD_PARITY){
		UCSRC |= ((1 << URSEL) | (1 << UPM1) | (1 << UPM0));
	}


	if(USART_BIT_MODE == UART_BIT_1_STOP_MODE){
		UCSRC |= ((1 << URSEL) & ~(1 << USBS));
	}
	else if(USART_BIT_MODE == UART_BIT_2_STOP_MODE){
		UCSRC |= ((1 << URSEL) | (1 << USBS));
	}


	if(USART_CLOCK_PARITY == USART_RISING_EDGE){
		UCSRC |= ((1<<URSEL) & ~(1<<UCPOL));
	}
	else if(USART_CLOCK_PARITY == USART_FALLING_EDGE){
		UCSRC |= ((1<<URSEL) | (1<<UCPOL));
	}


	if((USART_BAUD_PRESCALE_EQUATION == USART_BAUD_NORMAL_SPEED_EQUATION) && USART_OPERATION_MODE == USART_ASYNCHRONOUS_OPERATION){
		if(USART_BAUD_PRESCALE_NORMAL_SPEED>255){
			UBRRL = USART_BAUD_PRESCALE_NORMAL_SPEED;
			UCSRC = (~(1<<7) & (USART_BAUD_PRESCALE_NORMAL_SPEED>>8));
		}
		else if(USART_BAUD_PRESCALE_NORMAL_SPEED<=255){
			UBRRL = USART_BAUD_PRESCALE_NORMAL_SPEED;
		}
	}
	if((USART_BAUD_PRESCALE_EQUATION == USART_BAUD_PRESCALE_DOUBLE_SPEED) && USART_OPERATION_MODE == USART_ASYNCHRONOUS_OPERATION){
		if(USART_BAUD_PRESCALE_DOUBLE_SPEED>255){
			UBRRL = USART_BAUD_PRESCALE_DOUBLE_SPEED;
			UCSRC = (~(1<<7) & (USART_BAUD_PRESCALE_DOUBLE_SPEED>>8));

		}
		else if(USART_BAUD_PRESCALE_DOUBLE_SPEED<=255){
			UBRRL = USART_BAUD_PRESCALE_DOUBLE_SPEED;
		}
	}



	if(USART_OPERATION_MODE == USART_ASYNCHRONOUS_OPERATION){
		UCSRC |= ((1 << URSEL) & ~(1 << UMSEL));
	}
	else if(USART_OPERATION_MODE == USART_SYNCHRONOUS_OPERATION){
		CLEAR_BIT(UCSRA, U2X);
		UCSRC |= ((1 << URSEL) | (1 << UMSEL));
	}



	if(USART_TX_INTERRUNPT_MODE == ENABLE){
		SET_BIT(UCSRB, TXCIE);
	}
	else if(USART_TX_INTERRUNPT_MODE == DISABLE){
		CLEAR_BIT(UCSRB, TXCIE);
	}
	if(USART_RX_INTERRUNPT_MODE == ENABLE){
		SET_BIT(UCSRB, RXCIE);
	}
	else if(USART_RX_INTERRUNPT_MODE == DISABLE){
		CLEAR_BIT(UCSRB, RXCIE);
	}
}

void CALLBACK_INTERRUPT_USART_TX(void(*p0)(void)){

	INTERRUPT_USART_TX_CALL_BACK=p0;
}

void CALLBACK_INTERRUPT_USART_RX(void(*p1)(void)){

	INTERRUPT_USART_RX_CALL_BACK=p1;
}

ISR(USART_TXC_vect){

	INTERRUPT_USART_TX_CALL_BACK();

}

ISR(USART_RXC_vect){

	INTERRUPT_USART_RX_CALL_BACK();

}

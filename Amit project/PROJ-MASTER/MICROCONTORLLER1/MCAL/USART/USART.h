/*
 * UART.h
 *
 *  Created on: Aug 22, 2021
 *      Author: User
 */

#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_

#include "../../../MICROCONTORLLER1/MCAL/DIO/DIO.h"
#include "../../../MICROCONTORLLER1/MCAL/USART/USART_CONFIG.h"

void USART_Transmit( uint8 data );
void USART_Transmit_9BIT( unsigned int data );
uint8 USART_Receive( void );
unsigned int USART_Receive_9BIT( void );
void USART_INIT();
void CALLBACK_INTERRUPT_USART_TX(void(*p0)(void));
void CALLBACK_INTERRUPT_USART_RX(void(*p1)(void));

#endif /* MCAL_USART_USART_H_ */

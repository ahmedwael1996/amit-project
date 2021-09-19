/*
 * STD_types.h
 *
 *  Created on: Jul 30, 2021
 *      Author: M.Eltokhy
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum {
	Low, High
} Dio_Status_Type;

typedef enum {
	Input, Output
} Dio_Direction_Type;

typedef enum {
	PORT_A, PORT_B, PORT_C, PORT_D
} Dio_Port_Type;

typedef enum {
	PORT_A0,
	PORT_A1,
	PORT_A2,
	PORT_A3,
	PORT_A4,
	PORT_A5,
	PORT_A6,
	PORT_A7,
	PORT_B0,
	PORT_B1,
	PORT_B2,
	PORT_B3,
	PORT_B4,
	PORT_B5,
	PORT_B6,
	PORT_B7,
	PORT_C0,
	PORT_C1,
	PORT_C2,
	PORT_C3,
	PORT_C4,
	PORT_C5,
	PORT_C6,
	PORT_C7,
	PORT_D0,
	PORT_D1,
	PORT_D2,
	PORT_D3,
	PORT_D4,
	PORT_D5,
	PORT_D6,
	PORT_D7
} Dio_Pin;

typedef struct {
	Dio_Pin pin;
	Dio_Direction_Type direction;
} Dio_Init_Type;

#endif /* DIO_TYPES_H_ */

/*
 * DIO.h
 *
 *  Created on: Jul 30, 2021
 *      Author: M.Eltokhy
 */

#ifndef DIO_H_
#define DIO_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

#include "../../../MICROCONTORLLER1/BIT_MATH.h"
#include "../../../MICROCONTORLLER1/MCAL/DIO/DIO_types.h"
#include "../../../MICROCONTORLLER1/STD_TYPES.h"

void DIO_Write(Dio_Pin, Dio_Status_Type);
void DIO_Port_Write(Dio_Port_Type,uint8);
Dio_Status_Type DIO_Read(Dio_Pin);
void DIO_Init(void);

#endif /* DIO_H_ */


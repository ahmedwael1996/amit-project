/*
 * SPI_CONFIG.h
 *
 *  Created on: Aug 21, 2021
 *      Author: User
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

#define DISABLE						0
#define ENABLE						1

#define SPI_STATUS 					ENABLE

#define SPI_MASTER_MODE				0
#define SPI_SLAVE_MODE				1


#define SPI_MODE					SPI_SLAVE_MODE


#define SPI_SAMPLE					0
#define SPI_SETUP					1

#define SPI_FUNCTIONALLITY 			SPI_SAMPLE

#define SPI_FREQ_4					0
#define SPI_FREQ_16					1
#define SPI_FREQ_64					2
#define SPI_FREQ_128				3
#define SPI_FREQ_2_DOUBLE_SPEED		4
#define SPI_FREQ_8_DOUBLE_SPEED		5
#define SPI_FREQ_32_DOUBLE_SPEED	6
#define SPI_FREQ_64_DOUBLE_SPEED	7

#define SPI_FREQ_MODE				SPI_FREQ_16


#define MSB							0
#define LSB							1

#define SPI_DATA_ORDER				MSB


#define SPI_INTTERUPT_MODE			DISABLE



#endif /* MCAL_SPI_SPI_CONFIG_H_ */

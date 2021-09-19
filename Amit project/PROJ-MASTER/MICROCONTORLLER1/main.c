
#include "../MICROCONTORLLER1/MCAL/SPI/SPI.h"
#include "../MICROCONTORLLER1/MCAL/USART/USART.h"
#include "MCAL/DIO/DIO.h"

int main()
{

	SPI_INIT(); 	// Initializing our U1 MicroController as master//
	USART_INIT();	// Initializing our U1 MicroController in receiving mode//
	DIO_Init();		//Initializing our ports//
	uint8 data=0;	//	Initializing a Var to receive data of USART in it//
	while(1){
		_delay_ms(10);
		data=USART_Receive(); // calling USART receiving function//
		SPI_MASTER_TRANSMIT(data); // calling master transmit function with data received//
		_delay_ms(10);
	}
	return 0;
}

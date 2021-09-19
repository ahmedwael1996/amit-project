

#include "../MICROCONTROLLER2/MCAL/DIO/DIO.h"
#include "../MICROCONTROLLER2/MCAL/SPI/SPI.h"

int main()
{
	DIO_Init();	//Initializing our ports//
	SPI_INIT();	// Initializing our U1 MicroController as salve//
	while(1){
		_delay_ms(10);
		uint8 data=SPI_SLAVE_RECEIVE(); // calling salve receive function//
		if(data=='1'){
			TOGGLE_BIT(PORTA,0);		//if data == 1 then toggle first led//
		}else if(data=='2'){
			TOGGLE_BIT(PORTA,1);		//if data == 1 then toggle second led//
		}
	}
	return 0;
}

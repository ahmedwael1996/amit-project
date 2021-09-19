
#include "../../../MICROCONTORLLER1/MCAL/DIO/DIO.h"

Dio_Init_Type init_pins[] = { 	{ PORT_A4, Output },{ PORT_A5, Output },
								{ PORT_A6, Output },{ PORT_A7, Output },
								{ PORT_B1, Output },{ PORT_B2, Output } };



void DIO_Write(Dio_Pin pin, Dio_Status_Type status) {
	Dio_Port_Type port_var = pin / 8;
	Dio_Pin pin_var = pin % 8;
	switch (port_var) {
	case PORT_A:
		if (status) {
			SET_BIT(PORTA, pin_var);
		} else {
			CLEAR_BIT(PORTA, pin_var);
		}
		break;
	case PORT_B:
		if (status) {
			SET_BIT(PORTB, pin_var);
		} else {
			CLEAR_BIT(PORTB, pin_var);
		}
		break;
	case PORT_C:
		if (status) {
			SET_BIT(PORTC, pin_var);
		} else {
			CLEAR_BIT(PORTC, pin_var);
		}
		break;
	case PORT_D:
		if (status) {
			SET_BIT(PORTD, pin_var);
		} else {
			CLEAR_BIT(PORTD, pin_var);
		}
		break;
	}
}

void DIO_Port_Write(Dio_Port_Type port, uint8 data) {
	switch (port) {
	case PORT_A:
		PORTA = data;
		break;
	case PORT_B:
		PORTB = data;
		break;
	case PORT_C:
		PORTC = data;
		break;
	case PORT_D:
		PORTD = data;
		break;
	}
}

Dio_Status_Type DIO_Read(Dio_Pin pin) {
	Dio_Port_Type port_var = pin / 8;
	Dio_Pin pin_var = pin % 8;
	switch (port_var) {
	case PORT_A:
		if (GET_BIT(PINA, pin_var)) {
			return High;
		} else {
			return Low;
		}
		break;
	case PORT_B:
		if (GET_BIT(PINB, pin_var)) {
			return High;
		} else {
			return Low;
		}
		break;
	case PORT_C:
		if (GET_BIT(PINC, pin_var)) {
			return High;
		} else {
			return Low;
		}
		break;
	case PORT_D:
		if (GET_BIT(PIND, pin_var)) {
			return High;
		} else {
			return Low;
		}
		break;
	default:
		break;
	}
	return Low;
}

void DIO_Init(void) {
	for (int i = 0; i < (sizeof(init_pins) / sizeof(init_pins[0])); i++) {
		Dio_Pin pin = init_pins[i].pin % 8;
		switch ((init_pins[i].pin/8)) {
		case PORT_A:
			if (init_pins[i].direction) {
				SET_BIT(DDRA, pin);
			} else {
				CLEAR_BIT(DDRA, pin);
			}
			break;
		case PORT_B:
			if (init_pins[i].direction) {
				SET_BIT(DDRB, pin);
			} else {
				CLEAR_BIT(DDRB, pin);
			}
			break;
		case PORT_C:
			if (init_pins[i].direction) {
				SET_BIT(DDRC, pin);
			} else {
				CLEAR_BIT(DDRC, pin);
			}
			break;
		case PORT_D:
			if (init_pins[i].direction) {
				SET_BIT(DDRD, pin);
			} else {
				CLEAR_BIT(DDRD, pin);
			}
			break;
		default:
			break;
		}
	}
}

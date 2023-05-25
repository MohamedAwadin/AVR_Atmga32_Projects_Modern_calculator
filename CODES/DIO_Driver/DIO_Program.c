#include "../std_Types.h"
#include "../BIT_Math.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {
	//u8 ErrorState = STD_OK;
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
		DDRA = Copy_u8Direction;
		break;
	case DIO_u8_PORTB:
		DDRB = Copy_u8Direction;
		break;
	case DIO_u8_PORTC:
		DDRC = Copy_u8Direction;
		break;
	case DIO_u8_PORTD:
		DDRD = Copy_u8Direction;
		break;
	}
}
void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
		PORTA = Copy_u8Value;
		break;
	case DIO_u8_PORTB:
		PORTB = Copy_u8Value;
		break;
	case DIO_u8_PORTC:
		PORTC = Copy_u8Value;
		break;
	case DIO_u8_PORTD:
		PORTD = Copy_u8Value;
		break;
	}
}

void DIO_voidSetPinDiraection(u8 Copy_u8Pin, u8 Copy_u8Direction) {
	u8 port = Copy_u8Pin / 8;
	u8 pin = Copy_u8Pin % 8 ;
	switch (port) {
	case DIO_u8_PORTA:

		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			CLEAR_BIT(DDRA, pin);
			break;
		case DIO_u8_OUTPUT:
			SET_BIT(DDRA, pin);
			break;
		}
		break;
	case DIO_u8_PORTB:

		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			CLEAR_BIT(DDRB, pin);
			break;
		case DIO_u8_OUTPUT:
			SET_BIT(DDRB, pin);
			break;
		}
		break;
	case DIO_u8_PORTC:

		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			CLEAR_BIT(DDRC, pin);
			break;
		case DIO_u8_OUTPUT:
			SET_BIT(DDRC, pin);
			break;
		}
		break;
	case DIO_u8_PORTD:
		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			CLEAR_BIT(DDRD, pin);
			break;
		case DIO_u8_OUTPUT:
			SET_BIT(DDRD, pin);
			break;
		}
		break;
	}

}
void DIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Value) {
	u8 port = Copy_u8Pin / 8;
	u8 Pin = Copy_u8Pin % 8 ;
	switch (port) {

	case DIO_u8_PORTA:

		switch (Copy_u8Value) {
		case DIO_u8_LOW:
			CLEAR_BIT(PORTA, Pin);
			break;
		case DIO_u8_HIGH:
			SET_BIT(PORTA, Pin);
			break;
		}
		break;
	case DIO_u8_PORTB:

		switch (Copy_u8Value) {
		case DIO_u8_LOW:
			CLEAR_BIT(PORTB, Pin);
			break;
		case DIO_u8_HIGH:
			SET_BIT(PORTB, Pin);
			break;
		}

		break;
	case DIO_u8_PORTC:

		switch (Copy_u8Value) {
		case DIO_u8_LOW:
			CLEAR_BIT(PORTC, Pin);
			break;
		case DIO_u8_HIGH:
			SET_BIT(PORTC, Pin);
			break;
		}

		break;
	case DIO_u8_PORTD:

		switch (Copy_u8Value) {
		case DIO_u8_LOW:
			CLEAR_BIT(PORTD, Pin);
			break;
		case DIO_u8_HIGH:
			SET_BIT(PORTD, Pin);
			break;
		}

		break;
	}
}

u8 DIO_u8ReadPinValue( u8 Copy_u8Pin){
	u8 port = Copy_u8Pin / 8;
	u8 Pin = Copy_u8Pin % 8 ;
	u8 LOC_u8PinState = 0;
	switch(port){
	case DIO_u8_PORTA:
		LOC_u8PinState = READ_BIT(PINA , Pin);
		break;
	case DIO_u8_PORTB:
		LOC_u8PinState = READ_BIT(PINB , Pin);
		break;
	case DIO_u8_PORTC:
		LOC_u8PinState = READ_BIT(PINC , Pin);
		break;
	case DIO_u8_PORTD:
		LOC_u8PinState = READ_BIT(PIND , Pin);
		break;
	}

	return LOC_u8PinState;
}


void DIO_voidActivePullUp( u8 Copy_u8Pin){
	u8 port = Copy_u8Pin / 8;
	u8 Pin = Copy_u8Pin % 8 ;

	switch(port){
	case DIO_u8_PORTA:
		CLEAR_BIT(DDRA,Pin);
		SET_BIT(PORTA,Pin);
		break;
	case DIO_u8_PORTB:
		CLEAR_BIT(DDRB,Pin);
		SET_BIT(PORTB,Pin);
		break;
	case DIO_u8_PORTC:
		CLEAR_BIT(DDRC,Pin);
		SET_BIT(PORTC,Pin);
		break;
	case DIO_u8_PORTD:
		CLEAR_BIT(DDRD,Pin);
		SET_BIT(PORTD,Pin);
		break;
	}
}

#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H


#include "../std_Types.h"
#include "../BIT_Math.h"


#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3



#define DIO_u8_PIN_A0	0
#define DIO_u8_PIN_A1	1
#define DIO_u8_PIN_A2	2
#define DIO_u8_PIN_A3	3
#define DIO_u8_PIN_A4	4
#define DIO_u8_PIN_A5	5
#define DIO_u8_PIN_A6	6
#define DIO_u8_PIN_A7	7
#define DIO_u8_PIN_B0	8
#define DIO_u8_PIN_B1	9
#define DIO_u8_PIN_B2	10
#define DIO_u8_PIN_B3	11
#define DIO_u8_PIN_B4	12
#define DIO_u8_PIN_B5	13
#define DIO_u8_PIN_B6	14
#define DIO_u8_PIN_B7	15
#define DIO_u8_PIN_C0	16
#define DIO_u8_PIN_C1	17
#define DIO_u8_PIN_C2	18
#define DIO_u8_PIN_C3	19
#define DIO_u8_PIN_C4	20
#define DIO_u8_PIN_C5	21
#define DIO_u8_PIN_C6	22
#define DIO_u8_PIN_C7	23
#define DIO_u8_PIN_D0	24
#define DIO_u8_PIN_D1	25
#define DIO_u8_PIN_D2	26
#define DIO_u8_PIN_D3	27
#define DIO_u8_PIN_D4	28
#define DIO_u8_PIN_D5	29
#define DIO_u8_PIN_D6	30
#define DIO_u8_PIN_D7	31



#define DIO_u8_OUTPUT		1
#define DIO_u8_INPUT        0
#define DIO_u8_PORT_OUTPUT  0xFF


#define DIO_u8_PORT_LOW    0
#define DIO_u8_PORT_HIGH   0xFF

#define DIO_u8_HIGH			1
#define DIO_u8_LOW			0

void DIO_voidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction);

void DIO_voidSetPortValue (u8 Copy_u8Port , u8 Copy_u8Value);

void DIO_voidSetPinDiraection (u8 Copy_u8Pin , u8 Copy_u8Direction);
void DIO_voidSetPinValue (u8 Copy_u8Pin , u8 Copy_u8Value);

u8 DIO_u8ReadPinValue( u8 Copy_u8Pin);
void DIO_voidActivePullUp(u8 Copy_u8Pin);

#define STD_NOK 0
#define STD_OK 1

#endif

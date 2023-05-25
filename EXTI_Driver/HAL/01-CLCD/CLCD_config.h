/*
 * CLCD_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A4 Center
 */

#ifndef HAL_01_CLCD_CLCD_CONFIG_H_
#define HAL_01_CLCD_CLCD_CONFIG_H_

/* CLCD_DATA_PORT -> OPTIONS
 *
 *  1- DIO_u8_PORTA
 *  2- DIO_u8_PORTB
 *  3- DIO_u8_PORTC
 *  4- DIO_u8_PORTD
 *
 */

#define CLCD_DATA_PORT    DIO_u8_PORTA


/* CLCD_CONTROL_PORT -> OPTIONS
 *
 *  1- DIO_u8_PORTA
 *  2- DIO_u8_PORTB
 *  3- DIO_u8_PORTC
 *  4- DIO_u8_PORTD
 *
 */

#define CLCD_CONTROL_PORT    DIO_u8_PORTB

/* CLCD_RS_PIN , CLCD_EN_PIN -> OPTIONS
 *
 *  X -> (PORT of PIN) -> [{PORTA=A},{PORTB=B},{PORTC=C},{PORTD=D}]
 *  1- DIO_u8_PIN_X0
 *  2- DIO_u8_PIN_X1
 *  3- DIO_u8_PIN_X2
 *  4- DIO_u8_PIN_X3
 *  5- DIO_u8_PIN_X4
 *  6- DIO_u8_PIN_X5
 *  7- DIO_u8_PIN_X6
 *  8- DIO_u8_PIN_X7
 *
 */
#define CLCD_RS_PIN          DIO_u8_PIN_B0
#define CLCD_RW_PIN          DIO_u8_PIN_B1
#define CLCD_EN_PIN          DIO_u8_PIN_B2

static u8 LOC_u8StaticArr [] = {
		  0x00,0x00,0x0F,0x08,0x08,0x1F,0x00,0x00,				//First Character
		  0x00,0x00,0x00,0x0E,0x0B,0x0E,0x02,0x0E,					//Second Character
		  0x04,0x00,0x0F,0x09,0x1F,0x00,0x00,0x00,					//Third Character
		  0x00,0x00,0x04,0x04,0x1F,0x00,0x0A,0x00,					//Fourth Character
		  0x00,0x00,0x08,0x00,0x17,0x14,0x1C,0x00,					//Fifth Character
		  0x02,0x04,0x08,0x10,0x10,0x08,0x04,0x02,					//sixth Character
		  0x06,0x08,0x08,0x04,0x1F,0x04,0x08,0x0E,					//7th Character
		  0x00,0x00,0x1E,0x12,0x13,0x12,0x1E,0x00,					//8th Character
};


/*
 * CLCD_u8_INTEFACE_DATA_LENGTH -> OPTIONS
 *
 * 1- CLCD_u8_4_DATA_LENGTH
 * 2- CLCD_u8_8_DATA_LENGTH

 */
#define CLCD_u8_INTEFACE_DATA_LENGTH		CLCD_u8_8_DATA_LENGTH

/*
	Cursor SET:-
		CLCD_CURSOR_OFF
		CLCD_CURSOR_ON
*/

#define CLCD_DISPLAY_CURSOR		CLCD_CURSOR_OFF




#endif /* HAL_01_CLCD_CLCD_CONFIG_H_ */

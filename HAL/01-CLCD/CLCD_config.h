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

#endif /* HAL_01_CLCD_CLCD_CONFIG_H_ */

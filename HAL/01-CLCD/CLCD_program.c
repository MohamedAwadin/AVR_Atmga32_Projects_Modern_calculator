/*
 * CLCD_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: A4 Center
 */

#include "../../Servicse/std_Types.h"
#include "../../Servicse/BIT_Math.h"

#include "../../MCAL/01-DIO/DIO_interface.h"

#include "util/delay.h"
#include "CLCD_config.h"
#include "CLCD_private.h"
#include "CLCD_Interface.h"





#include"CLCD_Interface.h"

void CLCD_voidInit(void){
	DIO_voidSetPortDirection(CLCD_DATA_PORT,DIO_u8_PORT_OUTPUT);
	DIO_voidSetPinDiraection(CLCD_EN_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDiraection(CLCD_RS_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDiraection(CLCD_RW_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinValue(CLCD_RW_PIN,DIO_u8_LOW);
	_delay_ms(50);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_Set_Funcation);
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_CONTROL_Funcation);
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_CLEAR_Funcation);
	_delay_ms(5);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_ENTRYMODE_Funcation);





}
void CLCD_voidSendData(u8 Copy_u8data){
	DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8data);
	DIO_voidSetPinValue(CLCD_RS_PIN,DIO_u8_HIGH);
	/*Applying Falling EDGE IN ENABLE PIN*/
	DIO_voidSetPinValue(CLCD_EN_PIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_EN_PIN,DIO_u8_LOW);
	_delay_ms(1);
}
void CLCD_voidSendCommand(u8 Copy_u8Command){
	    DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Command);
		DIO_voidSetPinValue(CLCD_RS_PIN,DIO_u8_LOW);
		/*Applying Falling EDGE IN ENABLE PIN*/
		DIO_voidSetPinValue(CLCD_EN_PIN,DIO_u8_HIGH);
		_delay_ms(1);
		DIO_voidSetPinValue(CLCD_EN_PIN,DIO_u8_LOW);
		_delay_ms(1);
}
void CLCD_voidSendString(s8 * Copy_u8PtrString){
	u8 LOC_u8Iterator = 0 ;
	while(Copy_u8PtrString[LOC_u8Iterator] != '\0'){
		CLCD_voidSendData(Copy_u8PtrString[LOC_u8Iterator]);
		LOC_u8Iterator ++ ;

	}
}

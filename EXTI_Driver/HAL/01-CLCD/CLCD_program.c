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
#if CLCD_u8_INTEFACE_DATA_LENGTH == CLCD_u8_8_DATA_LENGTH

	_delay_ms(50);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_Set_Funcation);
	_delay_ms(1);
#if CLCD_DISPLAY_CURSOR == CLCD_CURSOR_OFF
	CLCD_voidSendCommand(0b00001100);
#elif CLCD_DISPLAY_CURSOR == CLCD_CURSOR_ON
	CLCD_voidSendCommand(0b00001110);
#endif
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_CLEAR_Funcation);
	_delay_ms(5);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_ENTRYMODE_Funcation);



#elif CLCD_u8_INTEFACE_DATA_LENGTH  == CLCD_u8_4_DATA_LENGTH

	_delay_ms(50);
	CLCD_voidSendCommend(0b00100000);
	CLCD_voidSendCommend(0b00100000);
	CLCD_voidSendCommend(0b11000000);
	_delay_ms(1);
	CLCD_voidSendCommend(0b00000000);

#if CLCD_DISPLAY_CURSOR == CLCD_CURSOR_OFF
	CLCD_voidSendCommend(0b11000000);
#elif	CLCD_DISPLAY_CURSOR == CLCD_CURSOR_ON
	CLCD_voidSendCommend(0b11100000);
#endif


	_delay_ms(1);
	CLCD_voidSendCommend(0b00000000);
	CLCD_voidSendCommend(0b00010000);
	_delay_ms(5);
	CLCD_voidSendCommend(0b00000000);
	CLCD_voidSendCommend(0b01100000);
#endif
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

void CLCD_voidSendNumber(u64 Copy_u64Number){
	u64 LOC_u64Reversed =1 ;
	if (Copy_u64Number == 0){
		CLCD_voidSendData('0');
	}
	else {
		while(Copy_u64Number != 0){
			LOC_u64Reversed = (LOC_u64Reversed * 10 ) + (Copy_u64Number % 10);
			Copy_u64Number = Copy_u64Number / 10 ;
		}
		while(LOC_u64Reversed != 1 ){
			CLCD_voidSendData((LOC_u64Reversed % 10) + '0');
			LOC_u64Reversed /= 10 ;

		}
	}
}
void CLCD_voidSetPosition(u8 Copy_u8Row , u8 Copyu8Coloum){
	if(Copy_u8Row== CLCD_u8_ROW_00){
		CLCD_voidSendCommand(CLCD_u8_DDRAM_OFFSET + Copyu8Coloum);
	}
	else{
		CLCD_voidSendCommand(CLCD_u8_DDRAM_OFFSET + CLCD_u8_DDRAM_ROW2_OFFSET + Copyu8Coloum);
	}
}
void CLCD_voidSendExtraChar(void){
	CLCD_voidSendCommand(CLCD_u8_CGRAM_OFFSET);
	u8 LOC_u8Iterator = 0;

	for(LOC_u8Iterator = 0 ; LOC_u8Iterator < (sizeof(LOC_u8StaticArr) / sizeof(LOC_u8StaticArr[LOC_u8Iterator])); LOC_u8Iterator++){
		CLCD_voidSendData(LOC_u8StaticArr[LOC_u8Iterator]);
	}
}
void CLCD_voidClearLCD(void){
	CLCD_voidSendCommand(CLCD_u8_CLEAR_LCD_COMMAND);
}


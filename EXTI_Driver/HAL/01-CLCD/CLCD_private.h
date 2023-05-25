/*
 * CLCD_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A4 Center
 */

#ifndef HAL_01_CLCD_CLCD_PRIVATE_H_
#define HAL_01_CLCD_CLCD_PRIVATE_H_

#define CLCD_u8_DISPLAY_Set_Funcation          0b00111100

#define CLCD_u8_DISPLAY_CONTROL_Funcation      0b00001100

#define CLCD_u8_DISPLAY_CLEAR_Funcation        0b00000001

#define CLCD_u8_DISPLAY_ENTRYMODE_Funcation    0b00000110


#define CLCD_u8_DDRAM_OFFSET                   0x80
#define CLCD_u8_DDRAM_ROW2_OFFSET              64

#define CLCD_u8_CGRAM_OFFSET		0x40

#define CLCD_u8_CLEAR_LCD_COMMAND	0b00000001

#define CLCD_u8_4_DATA_LENGTH			1
#define CLCD_u8_8_DATA_LENGTH			0




#define CLCD_CURSOR_ON	1
#define CLCD_CURSOR_OFF	0


#endif /* HAL_01_CLCD_CLCD_PRIVATE_H_ */

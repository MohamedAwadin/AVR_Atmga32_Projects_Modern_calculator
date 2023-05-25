/*
 * GIE_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: A4 Center
 */


#include "../../Servicse/BIT_Math.h"
#include "../../Servicse/std_Types.h"

#include "GIE_Interface.h"
#include "GIE_private.h"
#include "GIE_config.h"



void GIE_voidEnable(void){
	SET_BIT(SREG,GIE_BIT);
}
void GIE_voidDisable(void){
	CLEAR_BIT(SREG,GIE_BIT);
}

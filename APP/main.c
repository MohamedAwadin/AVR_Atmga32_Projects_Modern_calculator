


#include "../Servicse/std_Types.h"
#include "../Servicse/BIT_Math.h"



#include "../HAL/01-CLCD/CLCD_Interface.h"



#include "../MCAL/01-DIO/DIO_Interface.h"

#include "util/delay.h"



int main(void){
	CLCD_voidInit();
	CLCD_voidSendString("AWADIN");
	while(1){

	}
}



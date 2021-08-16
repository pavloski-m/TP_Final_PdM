/*=============================================================================
 * Author: Pablo Morzán
 * Date: 2021/08/15
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "leds.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

//================================FUNCICONES=================================

void  encenderLed(gpioMap_t led){

	if (led >= 40 || led <= 45){       // se chequea valor led
		gpioWrite(led, ON);

	}
}


void toggleLed(gpioMap_t led){
	gpioWrite(led, !gpioRead(led));		//se modifica el valor del led, para titilar.
}


void  apagarLeds(){     /* apagar todos los leds */

	gpioWrite( LEDR, OFF );
	gpioWrite( LEDG, OFF );
	gpioWrite( LEDB, OFF );
	gpioWrite( LED1, OFF );
    gpioWrite( LED2, OFF );
    gpioWrite( LED3, OFF );

}




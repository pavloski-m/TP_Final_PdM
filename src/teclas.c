/*=============================================================================
 * Author: Dany Tito - Pablo Morzán
 * Date: 2021/07/31
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "teclas.h"

/*=====[Definition macros of private constants]==============================*/

typedef enum{
	B_UP,
	B_FALL,
	B_DOWN,
	B_RAISE,

	B_QTY
}EstadosBotones;

static EstadosBotones tecla1;
static EstadosBotones tecla2;

static uint8_t press1 = 0;  //es el flag de presión de tecla
static uint8_t press2 = 0;  //es el flag de presión de tecla

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

//void buttonPressed(gpioMap_t tecla);
//void buttonReleased(gpioMap_t tecla);

delay_t delayTEC1;
delay_t delayTEC2;

//================================FUNCIONES=================================

void inicializarMEF_TEC1(void){
	if (gpioRead(TEC1)){
		tecla1 = B_UP;
	}
	else {tecla1 = B_DOWN;
	}
	delayConfig( &delayTEC1, 40 );
};

void inicializarMEF_TEC2(void){
	if (gpioRead(TEC2)){
		tecla2 = B_UP;
	}
	else {tecla2 = B_DOWN;
	}
	delayConfig( &delayTEC2, 40 );
};


uint8_t actualizarMEF_TEC1(void){
	switch (tecla1){

		case B_UP:
			if(!gpioRead(TEC1)){
				tecla1 = B_FALL;
			}
			break;

		case B_DOWN:
			if(gpioRead(TEC1)){
				tecla1 = B_RAISE;
				press1 = 0;
			}
			break;

		case B_RAISE:
			if(delayRead( &delayTEC1 )){
				if(gpioRead(TEC1)){
					tecla1 = B_UP;
				}
				else tecla1 = B_RAISE;
			}
			break;

		case B_FALL:
			if(delayRead( &delayTEC1 )){
				if(!gpioRead(TEC1)){
					tecla1 = B_DOWN;
					press1 = 1;
				}
				else tecla1 = B_UP;
			}
			break;

		}

return press1;
}

uint8_t actualizarMEF_TEC2(void){
	switch(tecla2){
	case B_UP :
		if(!gpioRead(TEC2)){
			tecla2 = B_FALL;
		}
		break;

	case B_DOWN :
		if(gpioRead(TEC2)){
			tecla2 = B_RAISE;
			press2 = 0;
		}
		break;

	case B_RAISE :
		if(delayRead( &delayTEC2 )){
			if(gpioRead(TEC2)){
				tecla2 = B_UP;
			}
		}
		break;

	case B_FALL :
		if(delayRead( &delayTEC2 )){
			if(!gpioRead(TEC2)){
				tecla2 = B_DOWN;
				press2 = 1;
			}
			else tecla2 = B_UP;
		}
		break;

	}
return press2;
}




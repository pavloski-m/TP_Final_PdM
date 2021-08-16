/*=============================================================================
 * Author: Pablo Morzán
 * Date: 2021/08/15
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "main.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/



int main(void){


   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();


   /* Declaración de variables locales */
   delay_t tiempobase;
   delayInit( &tiempobase, 500 );

   uint8_t valorTecla = 0;
   bool_t flagpress = 0;
   //Inicialización de MEF

   inicializarMEF_TEC1();
   inicializarMEF_TEC2();
   urofluxInit();

 /* ------------- REPETIR POR SIEMPRE ------------- */

    while(1) {

    //actualizaciones de MEF

    	if(actualizarMEF_TEC2() && flagpress == 0){
    	    valorTecla = 2;
    	    flagpress = 1;
    	}

    	if(actualizarMEF_TEC1() && flagpress == 0){
    		valorTecla = 1;
    		flagpress = 1;
    	}

    	if(delayRead(&tiempobase)){
    		urofluxUpdate(valorTecla);
    		flagpress = 0;
    		valorTecla = 0;
    	}


/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
    }

    return 0 ;

}





//================================FUNCICONES=================================


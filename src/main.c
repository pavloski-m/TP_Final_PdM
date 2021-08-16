/*=============================================================================
 * Author: Pablo Morzán
 * Date: 2021/08/15
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "main.h"


int main(void){


   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   /* Declaración de delay no bloqueante */
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


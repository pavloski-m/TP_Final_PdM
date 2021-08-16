/*=============================================================================
 * Author: Pablo Morzán
 * Date: 2021/08/15
 * Version: 1.0
 *===========================================================================*/
// FSM DECLARATIONS

#include "uroflux.h"

// Nombre de los estados MEF
typedef enum{
   STATE_NOADQ,
   STATE_INIT,
   STATE_ADQ,
   STATE_ERR,
   STATE_CANT
}statesUroflux;

int16_t pesoOffset = 0;
int16_t	muestra = 0;
int16_t pesoNeto = 0;
int16_t pesoMax = 1000;

static bool_t flagNOADQ = 0;
static bool_t flagADQ = 0;
static bool_t flagERR = 0;

// FSM IMPLEMENTATIONS

// Variable que almacena el estado actual
static statesUroflux Uroflujometro1;


// Se inicializa el uroflujómetro en No adquisición
void urofluxInit( void )
{
   	Uroflujometro1 = STATE_NOADQ;   // Cuando inicia no adquiere
   	adcConfig( ADC_ENABLE ); // habilito lectura de ADC
   	initUART();

}

// Se actualiza el estado del uroflujómetro
void urofluxUpdate( uint8_t tecla ){

   switch( Uroflujometro1 ){

      case STATE_NOADQ:

    	  if(flagNOADQ == 0){
    		  encenderLed(VERDE);
    		  msgNoAdq();
    		  flagNOADQ = 1;
    	  }

    	  if(tecla == 1){
    		  Uroflujometro1 = STATE_INIT;
    		  apagarLeds();
    		  flagNOADQ = 0;
    	  }
    	  break;


      case STATE_INIT:

    	  pesoOffset = adcRead( CH1 );

    	  msgOffset(pesoOffset);

		  if(pesoOffset >= pesoMax){
    		 Uroflujometro1 = STATE_ERR;}
    	  else{
    		  Uroflujometro1 = STATE_ADQ;
    		  apagarLeds();
    	  	  }

      break;


      case STATE_ADQ:

    	  if(!flagADQ){
    		  apagarLeds();
    		  msgAdq();
    		  flagADQ = 1;
    	  }

         if (tecla != 1 && tecla != 2){     // SI NO SE PRESIONA NINGUNA TECLA SE REALIZA LA RUTINA
        	 muestra = adcRead( CH1 );
        	 pesoNeto = muestra - pesoOffset;
        	 msgValor(pesoNeto);
        	 toggleLed(VERDE);

        	 if(pesoNeto <= -10 || muestra > pesoMax){
				 Uroflujometro1 = STATE_ERR;
				 flagADQ = 0;}
         }
         else{
        	 if (tecla == 1){
             	  Uroflujometro1 = STATE_INIT;
             	  flagADQ = 0;
             }
             else{
            	 Uroflujometro1 = STATE_NOADQ;
             	 flagADQ = 0;
             }
             }
      break;


      case STATE_ERR:
    	  if(!flagERR){
    	      	apagarLeds();
    	      	msgError();
    	      	flagERR = 1;
    	   }

    	  if (tecla != 1 && tecla != 2){
    		  toggleLed(ROJO);
    	  }
    	  else{
    		  apagarLeds();
    		  if (tecla == 1){
    			  Uroflujometro1 = STATE_INIT;
    			  flagERR = 0;
    		  }
    		  else{
    			  Uroflujometro1 = STATE_NOADQ;
    			  flagERR = 0;
    		  }
    	  }
      break;


      default:
    	  Uroflujometro1 = STATE_INIT;
      break;
   }
}

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

// FSM IMPLEMENTATIONS

// Variable que almacena el estado actual
static statesUroflux Uroflujometro1;


// FSM Error Handler Function
void urofluxError( void )
{
	Uroflujometro1 = STATE_ERR;    //En caso de error se inicializa
}

// Se inicializa el uroflujómetro en
void urofluxInit( void )
{
   	Uroflujometro1 = STATE_NOADQ;   // Cuando inicia no adquiere
   	adcConfig( ADC_ENABLE ); // habilito lectura de ADC
   	encenderLed(VERDE);
}

// Se actualiza el estado del uroflujómetro
void urofluxUpdate( uint8_t tecla ){


   switch( Uroflujometro1 ){

      case STATE_NOADQ:
         // PUEDE SER QUE SE ENCIENDA UN LED VERDE MOSTRANDO QUE PUEDE ADQUIRIR Y ESPERE LA INICIALIZACIÓN

    	  if(tecla == 1){
    		  Uroflujometro1 = STATE_INIT;
    		  apagarLeds();
    	  }
    	  //UART ESTADO NO ADQUISICIÓN
    	  break;

      case STATE_INIT:

    	  pesoOffset = adcRead( CH1 );
    	  //UART INICIA CON OFFSET DE VALOR DE OFFSET

    	  if(pesoOffset >= pesoMax){
    		  Uroflujometro1 = STATE_ERR;
    		  encenderLed(ROJO);
    		  //pesoOffset = 0;
    		  //UART ERROR
    	  }
    	  else{
    		  Uroflujometro1 = STATE_ADQ;
    		  apagarLeds();
    		  encenderLed(VERDE);
    		  //UART COMIENZA ADQUISICIÓN
    	  }
    	  //ENCENDER LED VERDE O ROJO DEPENDIENDO DEL RANGO DE VALOR
    	  //COLOCO FLAG DE INICIALIZADO Y CAMBIO EL ESTADO A STATE_ADQ SI EL VALOR ES ADECUADO

      break;

      case STATE_ADQ:

         if (tecla != 1 && tecla != 2){     // SI NO SE PRESIONA NINGUNA TECLA SE REALIZA LA RUTINA
        	 muestra = adcRead( CH1 );
        	 pesoNeto = muestra - pesoOffset;
        	 toggleLed(VERDE);

        	 if(pesoNeto <= -10){
				 Uroflujometro1 = STATE_ERR;
				 apagarLeds();
				 pesoOffset = 0;
				 break;
			  }

         }
         else{
        	 apagarLeds();
             if (tecla == 1){
             	  Uroflujometro1 = STATE_INIT;
             	  tecla = 0;
             	  apagarLeds();
             }
             else{
            	 Uroflujometro1 = STATE_NOADQ;
             	 tecla = 0;
             	 apagarLeds();
             	 encenderLed(VERDE);
             }
             }


      break;

      case STATE_ERR:
    	  if (tecla != 1 && tecla != 2){
    		  toggleLed(ROJO);
    	  }
    	  else{
    		  apagarLeds();
    		  //se puede enviar un mensaje diciendo que se sale de este estado...
    		  if (tecla == 1){
    			  Uroflujometro1 = STATE_INIT;
    			  tecla = 0;
    		  }
    		  else{
    			  Uroflujometro1 = STATE_NOADQ;
    			  tecla = 0;
    			  encenderLed(VERDE);
    		  }
    	  }
      break;

      default:
    	  Uroflujometro1 = STATE_INIT;
      break;
   }
}

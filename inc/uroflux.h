/*=============================================================================
 * Author: Pablo Morzán
 * Date: 2021/08/15
 * Version: 1.0
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __UROFLUX__
#define __UROFLUX__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>
//#include "sapi.h"
#include "leds.h"
#include "UART_Message.h"


/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/
/*=============================================================================
 * Function: urofluxError
 * Description: Una vez que entra en este valor se considera que la medición no es confiable. Para salir de este modo se debe presionar TEC2
 * Input: No recibe input
 * Output: No devuelve nada. Pero realiza un toggle de led rojo
 *===========================================================================*/
void urofluxError( void );

/*=============================================================================
 * Function: encenderLed
 * Description: Chequea si el led está en el rango permitido y lo enciende. Luego chequea si encendió.
 * Input: se le pasa el valor que hace referencia al led que se quiere encender
 * Output: Si led enciende devuelve 1 y si no 0
 *===========================================================================*/
void urofluxInit( void );

/*=============================================================================
 * Function: encenderLed
 * Description: Chequea si el led está en el rango permitido y lo enciende. Luego chequea si encendió.
 * Input: se le pasa el valor que hace referencia al led que se quiere encender
 * Output: Si led enciende devuelve 1 y si no 0
 *===========================================================================*/
void urofluxUpdate( uint8_t tecla );

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __UROFLUX__ */

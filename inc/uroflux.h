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
#include "leds.h"
#include "UART_Message.h"

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Prototypes (declarations) of public functions]=======================*/

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

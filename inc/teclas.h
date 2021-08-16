/*=============================================================================
 * Author: Pablo Morzán
 * Date: 2021/08/15
 * Version: 1.0
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __TECLAS_H__
#define __TECLAS_H__

/*=====[Inclusions of public function dependencies]==========================*/
#include "sapi.h"
#include <stdint.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/


/*=====[Public function-like macros]=========================================*/

/*=============================================================================
 * Function: inicializar MEF_TECx
 * Description: Se inicializa la MEF de las teclas dependiendo el estado en el que
 * 			se encuentran cuando se llama a la función. Tambien inicializa el delay
 * 			no bloqueante para los anti-rebote.
 * Input: No se le pasan parámetros.
 * Output: No retorna valores
 *===========================================================================*/
void inicializarMEF_TEC1(void);

void inicializarMEF_TEC2(void);



/*=============================================================================
 * Function: actualizarMEF_TECx
 * Description: En función del estado de los botones que se están chequeando se
 * 			genera una transicióń de UP a DOWN pasando por FALL y de DOWN a UP
 * 			pasando por RAISE.
 * Input: No se les pasan parametros. Las funciones ya están asociadas a un
 * 			boton de la placa.
 * Output: Se devuelve 1 en caso de que haya pasado de UP a DOWN, es decir si fue
 * 			presionado.
 *===========================================================================*/
uint8_t actualizarMEF_TEC1(void);

uint8_t actualizarMEF_TEC2(void);


/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __TECLAS_H__ */

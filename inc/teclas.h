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
 * Function: leerTecla
 * Description: Realiza un chequeo del estado de las teclas de la placa EDU-CIAA (TEC1,..,TEC4)
 * Input: No se le pasan parámetros. Accede al estado de las teclas 0 presionado - 1 sin presionar
 * Output: Devuelve que tecla está presionada. En caso de presionar dos, se devuelve la de valor de referencia mas bajo.
 *===========================================================================*/
void inicializarMEF_TEC1(void);

void inicializarMEF_TEC2(void);

uint8_t actualizarMEF_TEC1(void);

uint8_t actualizarMEF_TEC2(void);

/*=============================================================================
 * Function: accionTecla
 * Description: Dependiendo la tecla que se presiona se realizan distintas acciones
 * 		TEC1:secuencia con desplazamiento decreciente
 * 		TEC2:tiempo de permanencia de encendido del led: 150 ms
 * 		TEC3:tiempo de permanencia de encendido del led: 750 ms
 * 		TEC4:secuencia con desplazamiento creciente
 * Input: tecla presionada, puntero a varible que configura el retardo y al sentido de la secuencia
 * Output: No se devuelve nada. Se modifican las variables de input
 *===========================================================================*/


/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __TECLAS_H__ */

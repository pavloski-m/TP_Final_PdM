/*
 * UART_Message.h
 *
 *  Created on: 16 ago. 2021
 *      Author: Pablo Morzán
 */

#ifndef _UART_MESSAGE_H_
#define _UART_MESSAGE_H_

#include "sapi.h"

void initUART(void);

void msgNoAdq(void);

void msgAdq(void);

void msgOffset(int16_t Offset);

void msgValor(int16_t valor);

void msgError(void);

#endif /* _UART_MESSAGE_H_ */

/*
 * productoEscalar32.h
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#ifndef APP_INC_PRODUCTOESCALAR32_H_
#define APP_INC_PRODUCTOESCALAR32_H_



/*==================[inclusions]=============================================*/

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/**
 * Funcion que suma dos enteros de 32 bits y devuelve el resultado
 * @param firstOperand primer sumando
 * @param secondOperand segundo sumando
 * @return suma
 */
extern void productoEscalar32ASM (uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar);
extern void productoEscalar32C (uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar);
/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/


#endif /* APP_INC_PRODUCTOESCALAR32_H_ */

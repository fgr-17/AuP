/*
 * productoEscalar32.h
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#ifndef APP_INC_PRODUCTOESCALAR12_H_
#define APP_INC_PRODUCTOESCALAR12_H_



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
extern void productoEscalar12ASM (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);
extern void productoEscalar12C (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);
/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/


#endif /* APP_INC_PRODUCTOESCALAR32_H_ */

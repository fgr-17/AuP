/*
 * max.h
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#ifndef APP_INC_MAX_H_
#define APP_INC_MAX_H_



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
 * Funcion que busca el maximo de un array
 * @param firstOperand primer sumando
 * @param secondOperand segundo sumando
 * @return suma
 */
extern uint32_t maxASM 	(uint32_t * vectorIn, uint32_t longitud);
extern uint32_t maxC	(uint32_t * vectorIn, uint32_t longitud);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/


#endif /* APP_INC_MAX_H_ */

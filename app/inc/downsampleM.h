/*
 * max.h
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#ifndef APP_INC_DOWNSAMPLEM_H_
#define APP_INC_DOWNSAMPLEM_H_



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
 * Ejercicio 8: Realizar una función que reciba un vector de muestras signadas de 32 bits y lo decime
 * descartando una cada N muestras.
 * @param firstOperand primer sumando
 * @param secondOperand segundo sumando
 * @return suma
 */
extern void downsampleMASM 	(uint32_t * vectorIn, uint32_t* vectorOut, uint32_t longitud, uint32_t N);
extern void downsampleMC	(uint32_t * vectorIn, uint32_t* vectorOut, uint32_t longitud, uint32_t N);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/


#endif /* APP_INC_DOWNSAMPLEM_H_ */

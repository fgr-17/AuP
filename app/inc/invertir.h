/*
 * invertir.h
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#ifndef APP_INC_INVERTIR_H_
#define APP_INC_INVERTIR_H_



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
 * Ejercicio 9: Realizar una función que reciba un vector de muestras no signadas de 16 bits e invierta su orden.
 *
 * @param firstOperand primer sumando
 * @param secondOperand segundo sumando
 * @return
 */
extern void invertirASM (uint16_t * vector, uint32_t longitud);
extern void invertirC	(uint16_t * vector, uint32_t longitud);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/


#endif /* APP_INC_INVERTIR_H_ */

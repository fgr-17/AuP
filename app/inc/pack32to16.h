/*
 * productoEscalar32.h
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#ifndef APP_INC_PACK32TO16_H_
#define APP_INC_PACK32TO16_H_



/*==================[inclusions]=============================================*/

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/** @brief Mascara para quedarme con el word alto de una variable de 32 bits*/
#define WORD_ALTO_MASCARA			(0xFFFF0000)
/** @brief Cantidad de bits a desplazar el word alto hacia el word bajo*/
#define DESPLAZAMIENTO_BITS			16


/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/**
 * Funcion que suma dos enteros de 32 bits y devuelve el resultado
 * @param firstOperand primer sumando
 * @param secondOperand segundo sumando
 * @return suma
 */
extern void pack32to16ASM 	(uint32_t * vectorIn, uint16_t * vectorOut, uint32_t longitud);
extern void pack32to16C		(uint32_t * vectorIn, uint16_t * vectorOut, uint32_t longitud);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/


#endif /* APP_INC_PACK32TO16_H_ */

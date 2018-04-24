/*
 * corr.h
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#ifndef APP_INC_CORR_H_
#define APP_INC_CORR_H_



/*==================[inclusions]=============================================*/

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define CORR_L	8

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/**
 * Ejercicio 11:
 *

La correlación cruzada (del inglés cross correlation) es una operación usada para estudiar el
grado de similitud de dos señales y su fase relativa, aún en presencia de ruido. La correlación de dos
funciones da como resultado una nueva función llamada función de correlación. La fórmula de
cálculo es:

         n=0
corr [l]= ∑   x[n]*y[n−l]
	      N
Realizar una función que calcule la correlación entre dos vectores. Luego optimice utilizando
instrucciones SIMD
 *
 * @param firstOperand primer sumando
 * @param secondOperand segundo sumando
 * @return
 */

extern void corrC   (int16_t * vectorX, int16_t* vectorY,int16_t* vectorCorr, uint32_t longitud);

extern void corrASM (int16_t * vectorX, int16_t* vectorY,int16_t* vectorCorr, uint32_t longitud);

extern void corrSIMD (int16_t * vectorX, int16_t* vectorY,int16_t* vectorCorr, uint32_t longitud);
extern void corrSIMD2 (int16_t * vectorX, int16_t* vectorY,int16_t* vectorCorr, uint32_t longitud);
extern void corrSIMD3 (int16_t * vectorX, int16_t* vectorY,int16_t* vectorCorr, uint32_t longitud);
extern void corrSIMD4 (int16_t * vectorX, int16_t* vectorY,int16_t* vectorCorr, uint32_t longitud);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/


#endif /* APP_INC_CORR_H_ */

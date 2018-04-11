/*
 * invertir.h
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#ifndef APP_INC_ECO_H_
#define APP_INC_ECO_H_



/*==================[inclusions]=============================================*/

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/** @brief frecuencia de muestreo */
#define FS						(44100)
/** @brief cantidad de muestras de la sgn de entrada*/
// #define SGN_IN_L				(4096)
#define SGN_IN_L				(16)
/** @brief retardo del eco en milisegundos*/
#define RETARDO_T				(20)
/** @brief factor de escala del retardo */
#define RETARDO_ESC				(1000)
/** @brief retardo del eco en muestras */
// #define RETARDO_N				((RETARDO_T * FS) / RETARDO_ESC)
#define RETARDO_N				(4)

/** @brief cantidad de muestras de la sgn de salida */
#define SGN_OUT_L				(SGN_IN_L - RETARDO_N)

/** @brief atenuacion en bits de desplazamiento*/
#define ATT_BITS_DESP	(1)
/** @brief macro para atenuar la señal */
#define ATENUAR_MUESTRA_ECO(x)		(x >> ATT_BITS_DESP)


/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/**
 * Ejercicio 10:
 *
 * Realizar una función que recibe un vector de 4096 valores de 16 bits (signados), que
 * corresponden a muestras de audio tomadas a una tasa de muestreo de 44.100 muestras/s. La función
 * debe introducir un “eco” de la mitad de la amplitud de la muestra original a los 20ms de comenzada
 * la grabación.
 * Nota: El eco consiste en adicionar a la señal original, la propia señal original dividida por dos y
 * atrasada en 20ms.
 * Variante: Una vez implementada la función, programar una nueva versión que utilice las
 * instrucciones SIMD para optimizar la ejecución del algoritmo.
 *
 * @param firstOperand primer sumando
 * @param secondOperand segundo sumando
 * @return
 */
extern void ecoASM (int16_t * vectorIn, int16_t* vectorOut, uint32_t longitud);
extern void ecoC (int16_t * vectorIn, int16_t* vectorOut, uint32_t longitud);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/


#endif /* APP_INC_ECO_H_ */

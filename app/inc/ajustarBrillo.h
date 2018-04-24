/*
 * corr.h
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#ifndef APP_INC_AJUSTARBRILLO_H_
#define APP_INC_AJUSTARBRILLO_H_



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
 * Ejercicio de parcial:
 *

Se pide implementar una funcion en C y ASM que modifique el brillo de una imagen en escala de grises de 8 bits.

void ajustarBrillo (uint8_t ** imagen, uint32_t ancho, uint32_t alto, int8_t brillo);

Para efectuar el ajuste de brillo, se debera sumar (teniendo el cuidado de saturar) la cantidad de "brillo" a cada uno
de los pixeles. La imagen se conforma por una matriz de "ancho x alto" bytes, donde cada byte representa un pixel y el puntero
"imagen" indica su comienzo.
Nota: se obtendrá puntuación máxima implementando la funcion con instrucciones SIMD. Considere que tanto el ancho
como el largo de la imagen son multiplos de 4.

 */

void ajustarBrilloC (uint8_t**imagen, uint32_t ancho, uint32_t alto, int8_t brillo);
void ajustarBrilloASM (uint8_t ** imagen, uint32_t ancho, uint32_t alto, int8_t brillo);
void ajustarBrilloSIMD (uint8_t ** imagen, uint32_t ancho, uint32_t alto, int8_t brillo);



/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/


#endif /* APP_INC_CORR_H_ */

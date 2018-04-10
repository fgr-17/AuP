/** Ejemplo de archivo de assembler */

/* Copyright 2018, Facundo Larosa - Danilo Zecchin
 * All rights reserved.
 *
 * This file is part of arquitecturaDeMicroprocesadores.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
	/**
	 * Directiva al ensablador que permite indicar que se encarga de buscar
	 * la instruccion mas apropiada entre thumb y thumb2
	 UAL: unified assembly language: quiere decir que contiene codigo de thumb y arm
	 juntos, pero esto me permitiria correrlo en un procesador A que tiene modo ARM.

	 */
	.syntax unified

	/**
	 * .text permite indicar una seccion de codigo. Esto hace mandarlo a la seccion de codigo
	 */
	.text

	/**
	 * .global permite definir un simbolo exportable,
	 * es decir que podemos verlo desde otros modulos (equivalente a extern).
     * Definimos la rutina como global para que sea visible desde otros modulos.
     * esto me da el nombre de la funcion, es un archivo por funcion.
     */
	.global filtroVentana10ASM


	/**
	 * Indicamos que la siguiente subrutina debe ser ensamblada en modo thumb,
	 * entonces en las direcciones en el ultimo bit tendran el 1 para que se reconozcan como en modo thumb.
	 * Siempre hay que ponerla antes de la primer instruccion.
	 * Me dice que las instrucciones que vienen esta todo en modo thumb
	 */
	.thumb_func


/**
 *	prototipo de la funcion en C
 *
 *	void productoEscalar32ASM (uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar);
 *
 *	En r0 se cargara firstOperand y en r1 se carga secondOperand.

 * etiqueta que tiene que coincidir con el nombre de la funcion.
*/

#define vectorIn 		r0
#define vectorOut 		r1
#define longitud 		r2
#define acc	 			r3

#define indice_f		r4

#define puntero_i		r5
#define puntero_j		r6
#define puntero_y		r7

#define auxiliar		r8

#define divisor			r9

/** @brief cantidad de coeficientes del filtro */
#define FILTRO_L			10
/** @brief cantidad de bits a desplazar segun el tamaño del dato en bytes. 1 -> *2 -> 16 bytes */
#define DESP_16BITS			1


/*
 * el array se incrementa cada 4, en la ultima posicion la tengo en vector + (longitud - 1)*4
 */

filtroVentana10ASM:

   push 	{indice_f - divisor, lr}  								/* guardamos la direccion de retorno en la pila */

   mov		puntero_i, longitud
   sub 		puntero_i, 1											/* decremento el indice para recorrer desde arriba */

   ldr      divisor, =FILTRO_L

   mov 		puntero_y, longitud										/* El puntero de salida es de un array mas corto */
   sub		puntero_y, divisor										/* arranca de la longitud total menos el largo del filtro*/




lazo_vectorIn:

	mov		puntero_j, puntero_i									/* copio [i] en [j] */
	ldr		indice_f, =FILTRO_L										/* cargo la ctdad de muestras del filtro */
	sub		indice_f, 1												/* resto uno para llegar a cero al finalizar */

    mov		acc, 0													/* pongo en cero el acumulador */

	lazo_filtro:

	   ldrh 	auxiliar, [vectorIn, puntero_j, LSL DESP_16BITS]  		/* levanto un elemento desde el final hacia abajo */
	   add   	acc, auxiliar											/* sumo el valor obtenido al acumulador */
	   sub 		puntero_j, 1											/* decremento el puntero j */
	   subs		indice_f, 1												/* decremento el indice del filtro */
	   bpl		lazo_filtro												/* me fijo si ya recorri todas las muestras del filtro */


   udiv   	auxiliar, acc, divisor									/* divido por la cantidad de muestras del filtro */
   strh 	auxiliar, [vectorOut, puntero_y, LSL DESP_16BITS]		/* guardo en el array de salida */

   sub	 	puntero_i, 1											/* decremento el puntero global */
   subs		puntero_y, 1											/* decremento puntero de salida */
   bpl 		lazo_vectorIn											/* si llegue al final de la salida, salgo*/


	/* las unicas instrucciones con las que accedo a memoria son load y store */

	pop {indice_f  - divisor, pc}   /* retorno */

	/* otras alternativas para el retorno */
	/* 1. mov pc,lr
	/  2. bx lr */
	/* pop {pc} */

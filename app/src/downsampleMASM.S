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
	.global downsampleMASM


	/**
	 * Indicamos que la siguiente subrutina debe ser ensamblada en modo thumb,
	 * entonces en las direcciones en el ultimo bit tendran el 1 para que se reconozcan como en modo thumb.
	 * Siempre hay que ponerla antes de la primer instruccion.
	 * Me dice que las instrucciones que vienen esta todo en modo thumb
	 */
	.thumb_func


/**
 *	@brief prototipo de la funcion en C
 *
 *	void downsampleMASM 	(uint32_t * vectorIn, uint32_t* vectorOut, uint32_t longitud, uint32_t N);
 *
 *	En r0 se cargara firstOperand y en r1 se carga secondOperand.

 * etiqueta que tiene que coincidir con el nombre de la funcion.
*/

#define vectorIn 		r0
#define vectorOut 		r1
#define longitud		r2
#define N				r3

#define indiceIn		r4
#define indiceOut		r5
#define auxiliar		r6

#define DESP_32BITS		2

/*
 * el array se incrementa cada 4, en la ultima posicion la tengo en vector + (longitud - 1)*4
 */

downsampleMASM:

   push 	{indiceIn - auxiliar, lr}  														/* guardamos la direccion de retorno en la pila */
   // sub 		longitud, 1												/* decremento el registro longitud */

   ldr		indiceIn, =0
   ldr		indiceOut, =0


lazo:
   ldr	 	auxiliar, [vectorIn, indiceIn, LSL DESP_32BITS]  			/* levanto un elemento desde el comienzo */
   str		auxiliar, [vectorOut, indiceOut, LSL DESP_32BITS]			/* guardo en el vector de salida */
   add		indiceIn, N
   add		indiceOut, 1

   cmp		indiceIn, longitud
   bcc		lazo

   pop {indiceIn - auxiliar, pc}   /* retorno */

	/* otras alternativas para el retorno */
	/* 1. mov pc,lr
	/  2. bx lr */
	/* pop {pc} */

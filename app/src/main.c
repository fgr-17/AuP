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
 
/** @brief This is a simple blink example.
 */

/** \addtogroup blink Bare-metal blink example
 ** @{ */

/*==================[inclusions]=============================================*/

#include <stdint.h>

#include "main.h"
#include "board.h"
#include "zeros.h"

/*==================[macros and definitions]=================================*/

#define VEC_LONGITUD 16

/*==================[internal data declaration]==============================*/

uint32_t vec [VEC_LONGITUD];
/*==================[internal functions declaration]=========================*/

/** @brief hardware initialization function
 *	@return none
 */
static void initHardware(void);

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

static void initHardware(void)
{
	Board_Init();
	SystemCoreClockUpdate();
	//SysTick_Config(SystemCoreClock / 1000);
}


/** el registro DWT_CYCCNT cuenta los ciclos de maq, DWT_CTRL lo activa haciendo |1
 *
 * puedo reiniciar el CYCCNT cuando quiero, y guardarlo a cualquier variable.
 *
 * el reloj esta en 214MHz
 * */

/*==================[external functions definition]==========================*/


volatile uint32_t *DWT_CTRL = (uint32_t*) 0xE0001000;
volatile uint32_t *DWT_CYCCNT = (uint32_t*) 0xE0001004;


int main(void)
{   /* como no hago nada con las variables, pasa los valores por registros y no reserva memoria ni stack*/
	uint32_t aValue = 20,
			 otherValue = 30,
			 sumResult;

	uint32_t i = 0;

	uint32_t ciclos_asm = 0;
	uint32_t ciclos_c = 0;

	*DWT_CTRL |= 1;


	for(i = 0; i < VEC_LONGITUD; i++)
		vec[i] = i;

	*DWT_CYCCNT = 0;

	zerosC(vec, VEC_LONGITUD);
	ciclos_c = 	*DWT_CYCCNT;


	for(i = 0; i < VEC_LONGITUD; i++)
			vec[i] = i;

	*DWT_CYCCNT = 0;
	zerosAsm (vec, VEC_LONGITUD);

	ciclos_asm = *DWT_CYCCNT;




	initHardware();

	sumResult = asmSum(aValue, otherValue);

	while (1)
	{
		__WFI();
	}
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/

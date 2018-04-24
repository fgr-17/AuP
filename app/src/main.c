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
#include "productoEscalar32.h"
#include "filtroVentana10.h"
#include "pack32to16.h"
#include "max.h"
#include "downsampleM.h"
#include "invertir.h"
#include "eco.h"
#include "corr.h"

/*==================[macros and definitions]=================================*/

#define VEC_LONGITUD 1000
#define ARRAY_L 16
#define ARRAY_32	4
#define ARRAY_MAX	10


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


volatile uint32_t * DWT_CTRL   = (uint32_t *)0xE0001000;
volatile uint32_t * DWT_CYCCNT = (uint32_t *)0xE0001004;


volatile uint32_t ciclos_asm = 0;
volatile uint32_t ciclos_c = 0;


static void Ejercicio1(void);
static void Ejercicio2(void);
static void Ejercicio3(void);
static void Ejercicio4(void);
static void Ejercicio5(void);
static void Ejercicio6(void);
static void Ejercicio7(void);
static void Ejercicio8(void);
static void Ejercicio9(void);
static void Ejercicio10(void);
static void Ejercicio11(void);
static void EjercicioParcial (void);


int main(void)

{   /* como no hago nada con las variables, pasa los valores por registros y no reserva memoria ni stack*/
	uint32_t aValue = 20,
			 otherValue = 30,
			 sumResult;


	initHardware();

	// Ejercicio1();
	// Ejercicio2();
	// Ejercicio3();
	// Ejercicio4();
	// Ejercicio5();
	// Ejercicio6();
	// Ejercicio7();
	// Ejercicio8();
	// Ejercicio9();
	// Ejercicio10();
	// Ejercicio11();

	EjercicioParcial();

	sumResult = asmSum(aValue, otherValue);

	while (1)
	{
		__WFI();
	}
}

/**
 * @fn void Ejercicio1(void)
 *
 */


void Ejercicio1(void) {
	uint32_t i = 0;

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

}

/**
 * @fn void Ejercicio2(void)
 *
 */

void Ejercicio2 (void) {

	volatile uint32_t arrayEntrada [ARRAY_L];
	volatile uint32_t arraySalida [ARRAY_L];

	volatile uint32_t ganancia = 2;
	uint32_t i;

	for (i = 0; i < ARRAY_L; i++){
		arrayEntrada[i] = i;
		arraySalida[i] = 0;
	}


	productoEscalar32C(arrayEntrada, arraySalida, ARRAY_L, ganancia);

	for (i = 0; i < ARRAY_L; i++){
		arrayEntrada[i] = i;
		arraySalida[i] = 0;
	}
	productoEscalar32ASM(arrayEntrada, arraySalida, ARRAY_L, ganancia);


	return;
}


/**
 * @fn void Ejercicio3(void)
 *
 */


void Ejercicio3 (void) {

	volatile uint16_t arrayEntrada [ARRAY_L];
	volatile uint16_t arraySalida [ARRAY_L];

	volatile uint16_t ganancia = 2;
	uint16_t base = 1 << 14;
	uint32_t i;

	for (i = 0; i < ARRAY_L; i++){
		arrayEntrada[i] = i + base;
		arraySalida[i] = 0;
	}


	productoEscalar16C(arrayEntrada, arraySalida, ARRAY_L, ganancia);

	for (i = 0; i < ARRAY_L; i++){
		arrayEntrada[i] = i + base;
		arraySalida[i] = 0;
	}
	productoEscalar16ASM(arrayEntrada, arraySalida, ARRAY_L, ganancia);


	return;
}

/**
 * @fn void Ejercicio4(void)
 *
 */


void Ejercicio4 (void) {

	volatile uint16_t arrayEntrada [ARRAY_L];
	volatile uint16_t arraySalida [ARRAY_L];

	volatile uint16_t ganancia = 2;
	uint16_t base = (1 << 11) - 10;
	uint32_t i;

	for (i = 0; i < ARRAY_L; i++){
		arrayEntrada[i] = i + base;
		arraySalida[i] = 0;
	}


	productoEscalar12C(arrayEntrada, arraySalida, ARRAY_L, ganancia);

	for (i = 0; i < ARRAY_L; i++){
		arrayEntrada[i] = i + base;
		arraySalida[i] = 0;
	}
	productoEscalar12ASM(arrayEntrada, arraySalida, ARRAY_L, ganancia);


	return;
}

/**
 * @fn void Ejercicio5(void)
 *
 */


void Ejercicio5 (void) {

	volatile uint16_t arrayEntrada [ARRAY_L];
	volatile uint16_t arraySalida [ARRAY_L - FILTRO_L + 1];

	uint16_t base = 0;
	uint32_t i;

	for (i = 0; i < ARRAY_L; i++){
		arrayEntrada[i] = i + base;

		if(i < ARRAY_L - FILTRO_L + 1)
			arraySalida[i] = 0;

	}


	filtroVentana10C(arrayEntrada, arraySalida, ARRAY_L);

	for (i = 0; i < ARRAY_L; i++){

		arrayEntrada[i] = i + base;

		if(i < ARRAY_L - FILTRO_L + 1)
			arraySalida[i] = 0;

	}

	filtroVentana10ASM(arrayEntrada, arraySalida, ARRAY_L);

	return;
}
/**
 * @fn void Ejercicio6(void)
 *
 */


void Ejercicio6 (void) {


	uint32_t arrayEntrada [ARRAY_32] = {0x1234aabb, 0x2345bbcc, 0x3456ccdd, 0x45faddee};
	uint16_t arraySalida [ARRAY_32];

	uint32_t i = 0;

	for ( i = 0; i < ARRAY_32; i++)
		arraySalida [i] = 0;

	pack32to16C(arrayEntrada, arraySalida, ARRAY_32);

	for ( i = 0; i < ARRAY_32; i++)
		arraySalida [i] = 0;

	pack32to16ASM(arrayEntrada, arraySalida, ARRAY_32);



	return;
}

/**
 * @fn void Ejercicio7(void)
 *
 */


void Ejercicio7 (void) {

	uint32_t array [ARRAY_MAX] = {1, 43, 22, 432, 653, 2, 887, 47, 58, 321};

	uint32_t maximoC, maximoASM;

	maximoC = maxC(array, ARRAY_MAX);

	maximoASM = maxASM(array, ARRAY_MAX);
}



/**
 * @fn void Ejercicio8(void)
 *
 */


void Ejercicio8 (void) {

	volatile uint32_t arrayEntrada [ARRAY_L];
	volatile uint32_t arraySalida [ARRAY_DS_M];

	uint32_t i;

	for (i = 0; i < ARRAY_L; i++){

		arrayEntrada[i] = i;

		if(i < ARRAY_DS_M)
			arraySalida[i] = 0;
	}

	downsampleMC (arrayEntrada, arraySalida, ARRAY_L, M);
	downsampleMASM (arrayEntrada, arraySalida, ARRAY_L, M);


	return;
}

/**
 * @fn void Ejercicio9(void)
 *
 */


void Ejercicio9 (void) {

	volatile uint16_t arrayEntrada [ARRAY_L];
	uint32_t i;

	for (i = 0; i < ARRAY_L; i++){
		arrayEntrada[i] = i;
	}

	invertirC (arrayEntrada, ARRAY_L);
	invertirASM (arrayEntrada, ARRAY_L);

	return;
}

/**
 * @fn void Ejercicio10(void)
 *
 */


void Ejercicio10 (void) {

	volatile uint16_t arrayEntrada [SGN_IN_L];
	volatile uint16_t arraySalida [SGN_OUT_L];

	volatile ciclosC, ciclosASM, ciclosSIMD;

	uint32_t i;

	*DWT_CTRL |= 1;

	for (i = 0; i < ARRAY_L; i++){
		arrayEntrada[i] = i*2;
		if (i < SGN_OUT_L)
			arraySalida [i] = 0;
	}

	*DWT_CYCCNT = 0;
	ecoC(arrayEntrada, arraySalida, ARRAY_L);
	ciclosC = *DWT_CYCCNT;

	for (i = 0; i < SGN_OUT_L; i++){
			arraySalida [i] = 0;
	}

	*DWT_CYCCNT = 0;
	ecoASM (arrayEntrada, arraySalida, ARRAY_L);
	ciclosASM = *DWT_CYCCNT;

	for (i = 0; i < SGN_OUT_L; i++){
			arraySalida [i] = 0;
	}

	*DWT_CYCCNT = 0;
	ecoSIMD (arrayEntrada, arraySalida, ARRAY_L);
	ciclosSIMD = *DWT_CYCCNT;


	return;
}


/**
 * @fn void Ejercicio11(void)
 *
 */


void Ejercicio11 (void) {

	static int16_t x[CORR_L] = {1, 2, 3, 4, 5, 6, 7, 8}; //, 5, 4, 3, 2, 1}; //, 6, 7, 8};

	static int16_t y[CORR_L] = {0, -2, 4, -6, 8, 6, 7 , 9}; //, 1, 2, 3, 4, 11}; //, -10, 12, -14};

	static int16_t vcorr[CORR_L];

	uint32_t i;
	int32_t cuentaC, cuentaASM, cuentaSIMD, cuentaSIMD2, cuentaSIMD3, cuentaSIMD4;

	*DWT_CTRL |= 1;


	for(i = 0; i < CORR_L; i++)	{
		vcorr[i] = 0;
	}
	*DWT_CYCCNT = 0;
	corrC(x, y, vcorr, CORR_L);
	cuentaC = *DWT_CYCCNT;


	for(i = 0; i < CORR_L; i++)	{
		vcorr[i] = 0;
	}
	*DWT_CYCCNT = 0;
	corrASM(x, y, vcorr, CORR_L);
	cuentaASM = *DWT_CYCCNT;


	for(i = 0; i < CORR_L; i++)	{
		vcorr[i] = 0;
	}
	*DWT_CYCCNT = 0;
	corrSIMD(x, y, vcorr, CORR_L);
	cuentaSIMD = *DWT_CYCCNT;

	for(i = 0; i < CORR_L; i++)	{
		vcorr[i] = 0;
	}
	*DWT_CYCCNT = 0;
	corrSIMD2(x, y, vcorr, CORR_L);
	cuentaSIMD2 = *DWT_CYCCNT;


	for(i = 0; i < CORR_L; i++)	{
		vcorr[i] = 0;
	}
	*DWT_CYCCNT = 0;
	corrSIMD3(x, y, vcorr, CORR_L);
	cuentaSIMD3 = *DWT_CYCCNT;

	for(i = 0; i < CORR_L; i++)	{
		vcorr[i] = 0;
	}
	*DWT_CYCCNT = 0;
	corrSIMD4(x, y, vcorr, CORR_L);
	cuentaSIMD4 = *DWT_CYCCNT;
	return;


}

/**
 *
 * @fn static void EjercicioParcial (void)
 *
 *
 *
 */

uint8_t foto [4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};

static void EjercicioParcial (void)
{


	int8_t brillo = -2;

	ajustarBrilloC(foto, 4, 4, brillo );
	return;



}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/

/*
 * productoEscalar12C.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>


#define BITS_SAT	(12)
#define VALOR_MAX	((2 << (BITS_SAT - 1) ) - 1)

void productoEscalar12C (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar)
{
	uint32_t i = 0;
	uint16_t sat;

	for(i = 0; i < longitud; i++){
		sat = vectorIn[i] * escalar;

		if(sat > VALOR_MAX)
			sat = VALOR_MAX;

		vectorOut [i] = sat;
	}


	return;
}


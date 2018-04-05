/*
 * productoEscalar16C.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>

void productoEscalar16C (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar)
{
	uint32_t i = 0;

	for(i = 0; i < longitud; i++)
		vectorOut [i] = vectorIn[i] * escalar;

	return;
}


/*
 * productoEscalar32.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>

void productoEscalar32C (uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar)
{
	uint32_t i = 0;

	for(i = 0; i < longitud; i++)
		vectorOut [i] = vectorIn[i] * escalar;

	return;
}


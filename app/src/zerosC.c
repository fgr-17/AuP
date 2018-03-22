/*
 * zerosC.c
 *
 *  Created on: Mar 21, 2018
 *      Author: piro2
 */

#include <stdint.h>

void zerosC (uint32_t * vector, uint32_t longitud)
{
	uint32_t i = 0;

	for(i = 0; i < longitud; i++)
		vector [i] = 0;

	return;
}

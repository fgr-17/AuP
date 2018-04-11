/*
 * max.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>
#include "max.h"


/**
 * @fn void pack32to16C (uint32_t * vectorIn, uint16_t * vectorOut, uint32_t longitud);
 *
 * @author Federico G. Roux (froux@citedef.gob.ar)
 *
 */

uint32_t maxC (uint32_t * vectorIn, uint32_t longitud)
{
	uint32_t i = 0;
	uint32_t max = 0;

	for(i = 0; i < longitud; i++){

		if (vectorIn[i] > max){
			max = vectorIn[i];
		}

	}


	return max;
}


/*
 * corr.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>
#include "corr.h"


/**
 * @fn void ecoC (int16_t * vectorIn, int16_t* vectorOut, uint32_t longitud)
 *
 * @brief correlacion circular
 *
 * @author Federico G. Roux (froux@citedef.gob.ar)
 *
 */

void corrC   (int16_t * vectorX, int16_t* vectorY,int16_t *vectorCorr, uint32_t longitud)
{

	uint16_t l = 0;
	uint16_t n = 0;

	int16_t acc;


	for(l = 0; l < longitud; l++) {

		acc = 0;

		for(n = 0; n < longitud; n++) {

			if(n >= l)
				acc += vectorX[n] * vectorY[n - l];
			else
				acc += vectorX[n] * vectorY[longitud + n - l];
		}

		vectorCorr[l] = acc;

	}


	return;
}


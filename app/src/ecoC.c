/*
 * max.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>
#include "eco.h"


/**
 * @fn void ecoC (int16_t * vectorIn, int16_t* vectorOut, uint32_t longitud)
 *
 * @author Federico G. Roux (froux@citedef.gob.ar)
 *
 */

void ecoC (int16_t * vectorIn, int16_t* vectorOut, uint32_t longitud)
{

	uint32_t i = 0;
	uint32_t j = 0;

	int16_t muestra, muestraEco;

	for(i = RETARDO_N; i < longitud; i++) {

		j = i - RETARDO_N;
		muestra = vectorIn [i];
		muestraEco = ATENUAR_MUESTRA_ECO(vectorIn[j]);
		muestraEco += muestra;
		vectorOut[j] = muestraEco;
	}


	return;
}


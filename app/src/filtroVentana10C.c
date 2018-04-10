/*
 * filtroVentana10.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>


#define FILTRO_L	( 10 )

/**
 * @fn void filtroVentana10 (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
 *
 * @author Federico G. Roux (froux@citedef.gob.ar)
 *
 */

void filtroVentana10C (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn)
{
	uint32_t i = 0, j = 0;
	uint16_t acc, muestra_salida;

	for(i = 0; i < (longitudVectorIn - FILTRO_L + 1); i++){

		acc = 0;

		for (j = 0; j < FILTRO_L; j++ ) {

			acc += vectorIn[i + j];
		}

		muestra_salida = acc / FILTRO_L;
		vectorOut[i] = muestra_salida;

	}


	return;
}


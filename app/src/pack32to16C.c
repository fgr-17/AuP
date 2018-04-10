/*
 * filtroVentana10.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>
#include "pack32to16.h"


/**
 * @fn void pack32to16C (uint32_t * vectorIn, uint16_t * vectorOut, uint32_t longitud);
 *
 * @author Federico G. Roux (froux@citedef.gob.ar)
 *
 */

void pack32to16C (uint32_t * vectorIn, uint16_t * vectorOut, uint32_t longitud)
{
	uint32_t i = 0;
	uint32_t aux;

	for(i = 0; i < longitud; i++){

		aux = vectorIn [i];
		vectorOut [i] = (uint16_t) ((WORD_ALTO_MASCARA & aux) >> DESPLAZAMIENTO_BITS);

	}


	return;
}


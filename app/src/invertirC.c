/*
 * max.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>
#include "invertir.h"


/**
 * @fn void invertirC	(uint16_t * vector, uint32_t longitud);
 *
 * @author Federico G. Roux (froux@citedef.gob.ar)
 *
 */

void invertirC	(uint16_t * vector, uint32_t longitud)
{
	uint32_t i = 0;
	uint32_t j = 0;
	uint32_t temp;


	j = longitud - 1;

	while (i <= j) {

		temp = vector[j];					/* guardo una muestra desde el final */

		vector[j] = vector[i];				/* le asigno una muestra desde adelante*/

		vector[i] = temp;					/* asigno la muestra desde el final guardada en temp*/

		i++;								/* Incremento el contador del inicio */
		j--;								/* Decremento el contador del final */

	}


	return;
}


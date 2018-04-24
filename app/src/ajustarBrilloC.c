/*
 * ajustarBrilloC.c
 *
 *  Created on: Apr 4, 2018
 *      Author: piro2
 */

#include <stdint.h>
#include "ajustarBrillo.h"


/**
 * @fn void ajustarBrillo (uint8_t ** imagen, uint32_t ancho, uint32_t alto, int8_t brillo);
 *
 * @brief ajuste de brillo matriz
 *
 * @author Federico G. Roux (froux@citedef.gob.ar)
 *
 */

void ajustarBrilloC (uint8_t**imagen, uint32_t ancho, uint32_t alto, int8_t brillo)
{

	uint32_t x = 0;
	uint32_t y = 0;

	int32_t temp;
	int16_t acc;


	for(x = 0; x < ancho; x++) {

		for(y = 0; y < alto; y++) {

			temp = (uint8_t)((imagen + (x * ancho)) + y) + brillo;

			//imagen[x][y] = temp;

			asm("usat %0, #15, %1"
					:"=r" ( *(*(imagen + x) + y))
					:"r" (temp));

		}
	}


	return;
}

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

	uint32_t i = 0;
	uint32_t indiceMax;

	volatile int32_t temp;
	int16_t acc;

	indiceMax = ancho * alto;


	for(i = 0; i < indiceMax; i++) {
		temp =(uint8_t) *((uint8_t*)imagen + i) + brillo;

		asm("usat %0, #8, %1"
				:"=r" ( (uint8_t) *((uint8_t*)imagen + i))
				:"r" (temp));
	}


	return;
}

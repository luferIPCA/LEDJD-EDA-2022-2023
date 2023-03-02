/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  Implementa��o de Fun��es
 * Bibliotecas est�ticas (.lib) em C
 * \author lufer
 * \date   November 2020
 *********************************************************************/
#include "framework.h"

/**
 * Calcula a soma de dois valores inteiros.
 * 
 * \param x
 * \param y
 * \return 
 */
int soma(int x, int y) {
	return (x + y);
}

/**
 * Encontra o maior entre dois valores.
 * 
 * \param x
 * \param y
 * \return 
 */
int maior(int x, int y) {
	return ((x > y) ?  x : y);
}
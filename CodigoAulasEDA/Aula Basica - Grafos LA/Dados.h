/*****************************************************************//**
 * @file   Dados.h
 * @brief  
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Veiculo {
	int cod;
	struct Veiculo* next;
}Veiculo;



Veiculo* NovoVei(int i);

Veiculo* InsereVei(Veiculo* h, Veiculo* novo, bool* res);
void MostraLista(Veiculo* h);
void MostraListaRecursiva(Veiculo* h);

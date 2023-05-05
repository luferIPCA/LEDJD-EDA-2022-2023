/*****************************************************************//**
 * @file   Header.h
 * @brief  
 * 
 * @author lufer
 * @date   November 2022
 *********************************************************************/
#pragma once
#define N 20
#include <stdio.h>
#include <stdbool.h>

typedef struct Pessoa {
	int idade;
	char nome[N];
}Pessoa;

bool SaveArray(FILE* fp, Pessoa p[], int n);
bool ShowFile(FILE* fp);

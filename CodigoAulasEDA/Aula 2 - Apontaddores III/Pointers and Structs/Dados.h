#pragma once
#ifndef DADOS
#define DADOS

#include <stdbool.h>
#include "Data.h"
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

#define N 20
#define MAX 10		//máximo de jogos

typedef struct Bloco BlocoII;

struct Bloco {
	int x;
	char y;
	BlocoII* next;
};

typedef struct Jogo {
	int cod;
	char nome[N];
	char tipo;
	DATA data;
	Jogo *next;
}Jogo;

//typedef struct Jogo {
//	int cod;
//	char nome[N];
//	char tipo;
//	DATA data;
//	Jogo next;		
//}Jogo, *JogoPtr;

//JogoPtr head;

int InsereJogo(Jogo *jogos, Jogo j, int pos);
int InsereJogoII(Jogo *jogos, Jogo *j, int pos);

/* guarda os dados dos jogos num ficheiro binário */
bool gravarJogoBinario(char *nomeFicheiro, Jogo jogos[], int n);

/* ler jogos de um ficheiro binario */
bool lerJogosBinario(char *nomeFicheiro, Jogo jogos[]);

/*Verifica se determinado jogo existe*/
bool ExisteJogo(Jogo* jogos[], int cod, int n);

#pragma region ARRAYNORMALDEJOGOS

void mostraJogos(Jogo jogos[], int t);

#pragma endregion

#endif //

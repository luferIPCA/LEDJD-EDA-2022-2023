/*****************************************************************//**
 * @file   Dados.h
 * @brief   Listas Ligadas Simples
 *			Structs com Apontadores
 * @author lufer
 * @date   March 2023
 *********************************************************************/

//#pragma once
#ifndef DADOS
#define DADOS

#define MAXCHAR 200

#include <stdbool.h>
#include <stdlib.h>

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

#define N 20

typedef struct Jogo {
	int cod;
	char nome[N];
	char tipo;
}Jogo;

typedef struct JogosLista {
	Jogo jogo;
	struct JogosLista *next;
}JogosLista, *JogosListaPtr;


#pragma region ASSINATURAS

//Cria novo Jogo
JogosLista* criaJogo(Jogo *j);
//Insere novo jogo no início
JogosListaPtr InsereJogoInicio(JogosListaPtr h, Jogo* novo);
//Insere novo jogo no fim
JogosListaPtr InsereJogoFim(JogosListaPtr h, Jogo* novo);
//Insere novo jogo de forma ordenada
JogosListaPtr InsereJogoOrdenado(JogosListaPtr h, Jogo* novo);
//preserva inf n ficheiro
bool gravarJogoBinario(char *nomeFicheiro, JogosListaPtr h);
//ler inf do ficheiro
JogosListaPtr lerJogosBinario(char *nomeFicheiro);
//Encontra determinado jogo na lista
JogosListaPtr ProcuraJogo(JogosListaPtr h, int cod);
//Remover jogo da lista
JogosListaPtr RemoveJogo(JogosListaPtr h, int cod);
//verfica se jogo existe
bool ExisteJogo(JogosListaPtr h, int cod);
//apresenta todos os jogos
void MostraLista(JogosListaPtr h);
//apresenta ficha de jogo
void MostraJogo(JogosListaPtr nodo);
//constroi uma lista a partir de um array de inteiros. Não recursivo
JogosLista* ConsList(Jogo *v, int size);
//constroi uma lista a partir de um array de inteiros. Recursivo
JogosLista* ConsList(Jogo *v, int size);
JogosLista* ConsListRecII(Jogo v[], int i, int size);


//Conta Jogos de determinado tipo
int ContaJogos(JogosLista *h, char tipo);


//Ficheiros
bool LeDadosCSV(char fileName[]);
JogosLista* FileCSV2Lista(char fileName[]);

#pragma endregion

#endif
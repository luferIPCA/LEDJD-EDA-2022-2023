//-----------------------------------------------------------------------
// <copyright file="Duplas.c" company="IPCA">
//     Copyright IPCA. All rights reserved.
// </copyright>
// <date>2023</date>
// <author>lufer</author>
// <email>lufer@ipca.pt</email>
// <version>1.0</version>
// <desc>Manipular Listas Simplesmente Ligadas</desc>
//-----------------------------------------------------------------------


#include <stdio.h>
#include<string.h>
#include "Dados.h"



/*
Cria novo Jogo
*/
JogosLista* criaJogo(Jogo *j)
{
	JogosLista* newJogo = (JogosLista*)malloc(sizeof(JogosLista));
	newJogo->jogo = *j;
	newJogo->next = NULL;
	return newJogo;
}

/*
Insere um novo jogo no início da estrutura
*/
JogosListaPtr InsereJogoInicio(JogosListaPtr h, Jogo* novo) {

	//Verificar se o novo jogo já existe!!!
	if (ExisteJogo(h, novo->cod)) return h;	//se existir não insere!

	//Cria novo nodo na lista
	JogosListaPtr n = (JogosListaPtr)malloc(sizeof(JogosLista));
	n->jogo = *novo;
	n->next = NULL;
	//Ou
	//JogoLista* n = (JogoLista *)malloc(sizeof(JogoLista));

	if (h == NULL)		//Lista está vazia
	{
		h = n;
	}
	else
	{
		n->next = h;	//aponta para onde "h" está a apontar
		h = n;
	}
	return h;
}


/*
Insere jogo no final da lista
*/
JogosListaPtr InsereJogoFim(JogosListaPtr h, Jogo* novo) {
	//Verificar se o novo jogo já existe!!!
	if (ExisteJogo(h, novo->cod)) return h;	//se existir não insere!

	//criar jogo para a lista
	JogosListaPtr n = (JogosListaPtr)malloc(sizeof(JogosLista));
	n->jogo = *novo;
	n->next = NULL;

	if (h == NULL) {		//lista vazia
		h = n;
	}
	else
	{
		//Posicionar-se no fim da lista
		JogosListaPtr aux = h;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		//insere no fim da lista
		aux->next = n;
	}
	return h;
}


JogosLista* InsereJogoOrdenadoII(JogosLista* h, Jogo novo) {
	/*if (ExisteJogo(h, novo->cod)) return h;
	JogoListaPtr n = criaJogo(novo);
	if (h == NULL) {
		h = n;
	}
	else
	{
		JogoLista* aux = h;
		JogoLista* auxAnt = NULL;
		while (aux && aux->jogo.cod < novo->cod) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (auxAnt == NULL) {
			n->next = h;
			h = n;
		}
		else
		{
			auxAnt->next = n;
			n->next = aux;
		}
	}
	return h;*/
}

/*
Insere Jogo ordenado pelo código
*/
JogosLista* InsereJogoOrdenado(JogosLista* h, Jogo* novo) {
	if (ExisteJogo(h, novo->cod)) return h;
	JogosListaPtr n = criaJogo(novo);
	if (h == NULL) {
		h = n;
	}
	else
	{
		JogosLista* aux = h;
		JogosLista* auxAnt = NULL;
		while (aux && aux->jogo.cod < novo->cod) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (auxAnt == NULL) {
			n->next = h;
			h = n;
		}
		else
		{
			auxAnt->next = n;
			n->next = aux;
		}
	}
	return h;
}

/*
Mostra todos os jogos existentes na estrutura
*/
void MostraLista(JogosListaPtr h) {
	JogosListaPtr aux = h;
	while (aux) {		//(aux!=NULL)
		MostraJogo(aux);
		aux = aux->next;
	}
}

/*
//Mostra Nodo
*/
void MostraJogo(JogosListaPtr nodo) {
	if (nodo != NULL)
	{
		printf("\nFicha de Jogo:\nJogo= %s\n", nodo->jogo.nome);
		printf("Codigo= %d\n", nodo->jogo.cod);
		printf("Tipo= %c\n", nodo->jogo.tipo);
	}

}

/*
Remove jogo
*/
JogosListaPtr RemoveJogo(JogosListaPtr h, int cod) {
	
	if (h == NULL) return NULL;			//Lista vazia
	if (!ExisteJogo(h, cod)) return h;	//se não existe
	
	JogosListaPtr aux = h;
	JogosListaPtr auxAnt = NULL;

	//localizar registo a eliminar
	while (aux && aux->jogo.cod != cod) {
		auxAnt = aux;
		aux = aux->next;
	}
	if (auxAnt == NULL) {	//Eliminar à cabeça
		h = h->next;
		free(aux);
	}
	else					//Elimiar no meio
	{
		auxAnt->next = aux->next;
		free(aux);
	}
	return h;
}

/*
Verifica se jogo existe. Se existir devolve jogo!
*/
JogosLista* ProcuraJogo(JogosLista *h, int cod) {
	if (h == NULL) return NULL;
	else
	{
		JogosLista* aux = h;
		while (aux != NULL) {
			if (aux->jogo.cod == cod) 
				return (aux);
			aux = aux->next;
		}
		return NULL;
	}
}

/*
Verifica se jogo existe. Se existir devolve Bool!
*/
bool ExisteJogo(JogosListaPtr h, int cod) {
	if (h == NULL) return false;
	JogosListaPtr aux = h;
	while (aux != NULL) {
		if (aux->jogo.cod == cod) 
				return true;
		aux = aux->next;
	}
	return false;
}

/*
Contar jogos de determinado tipo, numa lista ligada
*/
int ContaJogos(JogosLista *h, char tipo) {
	int c = 0;
	JogosListaPtr aux = h;	//inicio da lista
	while (aux != NULL) {
		if (aux->jogo.tipo == tipo) {
			c++;
		}
		aux = aux->next;
	}
	return c;
}

/*
Conta jogos de determinado tipo num array de jogos
*/
int ContaJogosArray(Jogo v[], int size, char tipo) {
	int c = 0;	//contador
	//h1
	for (int i = 0; i < size; i++) {
		if (v[i].tipo == tipo) {
			c++;
		}
	}
	//h2
	/*int i = 0;
	while (i < size) {
		if (v[i].tipo == tipo) {
			c++;
		}
		i++;
	}*/
	return c;
}

/*
Constroi uma lista a partir de um array de Jogos
Não recursivo
*/
JogosLista* ConsList(Jogo *v, int size)
{
	JogosListaPtr h = NULL, aux;
	if (size <= 0) return NULL;

	for (int i = 0; i < size; i++)
	{
		//h = Append(v[i], h);
		h = InsereJogoFim(h, &v[i]);
	}
	return h;
}

/*
Constroi uma lista a partir de um array de Jogos
Recursivo
Versão 1
*/
JogosLista* ConsListRec(Jogo *v, int size)
{
	JogosListaPtr h = NULL, aux;

	if (size <= 0) return NULL;

	h = (JogosListaPtr)malloc(sizeof(JogosLista));
	h->jogo = v[0];
	h->next = ConsListRec(v + 1, size - 1);;

	return h;
}

/*
Constroi uma lista a partir de um array de Jogos
Recursivo
Versão 2
*/
JogosLista* ConsListRecII(Jogo v[], int i, int size)
{
	JogosListaPtr h = NULL, aux;

	if (size <= 0) return NULL;

	h = (JogosListaPtr)malloc(sizeof(JogosLista));
	h->jogo = v[i];
	h->next = ConsListRecII(v, i+1, size - 1);;

	return h;
}

// ========================= Ficheiros ============================

#pragma region FICHEIROS_BINARIOS

//Ver : https://www.geeksforgeeks.org/readwrite-structure-file-c/

/*
Preservar dados em ficheiro
*/
bool gravarJogoBinario(char *nomeFicheiro, JogosListaPtr h) {
	FILE *fp;

	if (h == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	//grava 1 registo de cada vez no ficheiro
	JogosListaPtr aux = h;
	Jogo auxJogo;
	while (aux) {		//while(aux!=NULL)
		auxJogo = aux->jogo;
		fwrite(&auxJogo, sizeof(Jogo), 1, fp);
		aux = aux->next;
	}
	fclose(fp);
	return true;
}

/*
Lê informação de ficheiro
*/
JogosListaPtr lerJogosBinario(char *nomeFicheiro){
	FILE *fp;
	JogosListaPtr h = NULL;
	Jogo *aux;

	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
	//lê n registos no ficheiro
	aux = (Jogo*)malloc(sizeof(Jogo));
	while (fread(aux, sizeof(Jogo), 1, fp)){
		//printf("Jogo=%s\n", aux->nome);
		h = InsereJogoInicio(h, aux);
		aux = (Jogo*)malloc(sizeof(Jogo));
	}
	fclose(fp);
	return h;
}
#pragma endregion

#pragma FICHEIROS_TEXTO
/**
 * @brief Mostra conteúdo de um ficheiro csv.
 * 
 * @param fileName
 * @return 
 * @author lufer
 *
 */
bool LeDadosCSV(char fileName[])
{
	char row[MAXCHAR];
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		perror("Problemas na leitura do ficheiro");
		return false;
	}

	while (feof(fp) != true)
	{
		fgets(row, MAXCHAR, fp);
		printf("Row: %s", row);
	}

	fclose(fp);
	return true;
}

/**
 * @brief Le ficheiro CSV e constroi Lista
 * 
 * @param fileName
 * @return 
 * @author lufer
 *
 */
JogosLista* FileCSV2Lista(char fileName[]) {
	JogosLista* head = NULL;	//lista
	FILE* fp;
	char row[MAXCHAR];	//auxiliar
	char* token;		//auxiliar analisar linha do ficheiro
	
	Jogo aux;

	fp = fopen(fileName, "r");
	if (fp == NULL) {
		perror("Problemas na leitura do ficheiro");
		exit(-1);
	}
	int rowNumber = 0;
	while (fgets(row, MAXCHAR, fp) != NULL)   //ou feof(fp) != true)
	{
		//printf("Row: %s", row);   //Debug
		if (rowNumber == 0)         //primeira linha com Column Headers
		{
			rowNumber++;
			continue;
		}

		token = strtok(row, ",");   //separador ","

		int t = 0;
		while (token != NULL)
		{
			//printf("Token: %s\n", token);
			switch (t) {
			case 0:
				aux.cod = atoi(token);
				break;
			case 1:
				strcpy(aux.nome, token);
				break;
			case 2:
				aux.tipo = token[0];
				break;
			}
			t++;
			token = strtok(NULL, ",");
		}
		//guarda o aux no array
		head = InsereJogoOrdenado(head, &aux);
	}
	fclose(fp);
	return head;
}
#pragma endregion


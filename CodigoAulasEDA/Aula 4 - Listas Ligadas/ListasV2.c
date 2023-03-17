/**
* author: lufer
* email:lufer@ipca.pt
* date: 2022
* Desc: Lista Ligadas Simples
*/

#include <stdio.h>
#include "Dados.h"


/*
Cria novo Jogo
*/
JogoLista* criaJogo(Jogo *j)
{
	JogoLista* newJogo = (JogoLista*)malloc(sizeof(JogoLista));
	newJogo->jogo = *j;
	newJogo->next = NULL;
	return newJogo;
}

/*
Insere um novo jogo no início da estrutura
*/
JogoListaPtr InsereJogoInicio(JogoListaPtr h, Jogo* novo) {

	//Verificar se o novo jogo já existe!!!
	if (ExisteJogo(h, novo->cod)) return h;	//se existir não insere!

	//Cria novo nodo na lista
	JogoListaPtr n = (JogoListaPtr)malloc(sizeof(JogoLista));
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
JogoListaPtr InsereJogoFim(JogoListaPtr h, Jogo* novo) {
	//Verificar se o novo jogo já existe!!!
	if (ExisteJogo(h, novo->cod)) return h;	//se existir não insere!

	//criar jogo para a lista
	JogoListaPtr n = (JogoListaPtr)malloc(sizeof(JogoLista));
	n->jogo = *novo;
	n->next = NULL;

	if (h == NULL) {		//lista vazia
		h = n;
	}
	else
	{
		//Posicionar-se no fim da lista
		JogoListaPtr aux = h;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		//insere no fim da lista
		aux->next = n;
	}
	return h;
}


JogoLista* InsereJogoOrdenadoII(JogoLista* h, Jogo novo) {
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
	}*/
}

/*
Insere Jogo ordenado pelo código
*/
JogoLista* InsereJogoOrdenado(JogoLista* h, Jogo* novo) {
	if (ExisteJogo(h, novo->cod)) return h;
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
}

/*
Mostra todos os jogos existentes na estrutura
*/
void MostraLista(JogoListaPtr h) {
	JogoListaPtr aux = h;
	while (aux) {		//(aux!=NULL)
		MostraJogo(aux);
		aux = aux->next;
	}
}

/*
//Mostra Nodo
*/
void MostraJogo(JogoListaPtr nodo) {
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
JogoListaPtr RemoveJogo(JogoListaPtr h, int cod) {
	
	if (h == NULL) return NULL;			//Lista vazia
	if (!ExisteJogo(h, cod)) return h;	//se não existe
	
	JogoListaPtr aux = h;
	JogoListaPtr auxAnt = NULL;

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
JogoLista* ProcuraJogo(JogoLista *h, int cod) {
	if (h == NULL) return NULL;
	else
	{
		JogoLista* aux = h;
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
bool ExisteJogo(JogoListaPtr h, int cod) {
	if (h == NULL) return false;
	JogoListaPtr aux = h;
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
int ContaJogos(JogoLista *h, char tipo) {
	int c = 0;
	JogoListaPtr aux = h;	//inicio da lista
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
Constroi uma lista a partir de um array de inteiros
Não recursivo
*/
JogoLista* ConsList(Jogo *v, int size)
{
	JogoListaPtr h = NULL, aux;
	if (size <= 0) return NULL;

	for (int i = 0; i < size; i++)
	{
		//h = Append(v[i], h);
		h = InsereJogoFim(h, &v[i]);
	}
	return h;
}

/*
Constroi uma lista a partir de um array de inteiros
Recursivo
Versão 1
*/
JogoLista* ConsListRec(Jogo *v, int size)
{
	JogoListaPtr h = NULL, aux;

	if (size <= 0) return NULL;

	h = (JogoListaPtr)malloc(sizeof(JogoLista));
	h->jogo = v[0];
	h->next = ConsListRec(v + 1, size - 1);;

	return h;
}

/*
Constroi uma lista a partir de um array de inteiros
Recursivo
Versão 2
*/
JogoLista* ConsListRecII(Jogo v[], int i, int size)
{
	JogoListaPtr h = NULL, aux;

	if (size <= 0) return NULL;

	h = (JogoListaPtr)malloc(sizeof(JogoLista));
	h->jogo = v[i];
	h->next = ConsListRecII(v, i+1, size - 1);;

	return h;
}

// ========================= Ficheiros ============================

#pragma region FICHEIROS

//Ver : https://www.geeksforgeeks.org/readwrite-structure-file-c/

/*
Preservar dados em ficheiro
*/
bool gravarJogoBinario(char *nomeFicheiro, JogoListaPtr h) {
	FILE *fp;

	if (h == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	//grava n registos no ficheiro
	JogoListaPtr aux = h;
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
JogoListaPtr lerJogosBinario(char *nomeFicheiro){
	FILE *fp;
	JogoListaPtr h = NULL;
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


//-----------------------------------------------------------------------
// <copyright file="List.c" company="IPCA">
//     Copyright IPCA. All rights reserved.
// </copyright>
// <date>2023</date>
// <author>lufer</author>
// <email>lufer@ipca.pt</email>
// <version></version>
// <desc>Manipulação de Listas Ligadas Simples</desc>
//-----------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Listas.h"

// ======================= LIST LIGADA SIMPLES ======================

//Cabeça da Lista
NodePtr head;				//equivalente a Node *head;


// ====================== Inserir elementos uma Lista ======================

/*
Insere à cabeça
*/
NodePtr InsertFirst(Node *np, Node *h) {
	if (h == NULL)
	{
		h = np;
	}
	else
	{
		np->next = h;
		h = np;
	}
	return h;
}


/*
Insere nova pessoa de forma ordenada
head não é global
*/
NodePtr InsertNode(NodePtr np, NodePtr h) {
	//Se lista vazia
	if (!h)				//if (h == NULL)
	{
		h = InsertFirst(np, h);
		return h;
	}
	else {				//h1: inserir ordenado
		NodePtr aux = h;
		NodePtr aux2 = aux;

		//Procura onde inserir
		while (aux != NULL && strcmp(aux->val,np->val)<0)	//crescente
		{
			aux2 = aux;
			aux = aux->next;
		}

		//se é para inserir no início
		if (aux == h)
		{
			h = InsertFirst(np, h);
		}

		//se é para inserir no meio
		else
		{
			if (aux == NULL) {		//no final
				aux2->next = np;
			}
			else {					//no início
				aux2->next = np;
				np->next = aux;
			}
			// ou apenas
			// aux2->next = np;		Porquê?
		}				
	}		
	return h;
}


// ====================== Outras Operações ======================

/*
Conta o número de nodos na Lista
*/
int Count(NodePtr h) {
	NodePtr aux = h;
	int c = 0;
	while (aux)
	{
		c++;
		aux = aux->next;
	}
	return c;
}


/*
Apaga elemento da Lista
*/
NodePtr DeleteNode(char *val, NodePtr h) {

	if (!h)				//Lista vazia...não tem nada que eliminar
	{		
		return h;
	}
	else {				
		NodePtr aux = h;
		NodePtr aux2 = aux;
		//Procura onde eliminar		
		while (aux != NULL && strcmp(aux->val,val)!=0)	
		{
			aux2 = aux;
			aux = aux->next;
		}
		//se é no início
		if (aux == h)
		{
			aux = h;
			h = h->next;
			//free(aux->val);	//atenção
			free(aux);
		}
		//se é no meio
		else
		{
			if (aux != NULL) {	
				aux2->next = aux->next;
				free(aux);
			}
			
		}
	}
	return h;
}

/*
Elimina toda a lista
*/
void DeleteAll(Node* h) {
	Node* aux = h;
	while (h) {
		aux = h;
		h = h->next;
		//free(aux->val);	//atenção
		free(aux);
	}
}


/*
Encontrar um registo!
*/
Node* Find(char *val, Node* h) {
	if (!h) return NULL;
	Node* aux = h;
	while (aux != NULL && strcmp(aux->val,val)!=0) aux = aux->next;
	return aux;
}


/*
Verifica se existe
*/
bool Exist(char *val, NodePtr h) {
	if (!h) return false;
	NodePtr aux = h;
	//while (aux != NULL && strcmp(aux->val, val) != 0) aux = aux->next;
	aux = Find(val, h);
	if (aux == NULL) return false;
	return true;
}

/*
Percorre e mostra a lista!
*/
void ShowList(NodePtr h) {
	NodePtr aux = h;
	while (aux) {			//mesmo que while(aux!=NULL)
		ShowNode(aux);
		aux = aux->next;
	}
}

/*
Percorre e mostra a lista...recursivamente!
*/
void ShowListRec(NodePtr h) {
	if (h) ShowNode(h);
	if (h->next) ShowListRec(h->next);	
}


// =================== Manipular Ficheiros =====================

/*
Grava Lista em Ficheiro binário
*/
bool SaveList(NodePtr h,char* fileName) {
	//testar file Path -> return false!
	FILE *fp; 
	if (h == NULL) return false;
	if ((fp = fopen(fileName, "ab")) == NULL)
	{
		return false;
	}

	Node *holdNext;
	NodeFile aux;
	Node* current = h;
	while (current != NULL) {
		/*holdNext = current->next;
		current->next = NULL;*/
		strcpy(aux.val,current->val);
		//fseek(fp, 0, SEEK_END);
		fwrite(&aux, sizeof(NodeFile), 1, fp);
		current = current->next;
		//holdNext = NULL;
	}
	fclose(fp);
	fp = NULL;
	return true;
}

/*
Carrega Lista de ficheiro binário
*/
bool LoadControled(Node **h, char* fileName) {
	FILE *fp;
	bool succ = true;
	fp = fopen(fileName, "rb");
	if (fp == NULL) return false;

	//Garantir que Lista está vazia
	DeleteAll(*h);		//Atenção: viola regras do SOLID
	*h = NULL;	
	//ler e construir lista
	Node *aux;
	NodeFile auxFile;
	
	while (fread(&auxFile, sizeof(NodeFile), 1, fp) != 0) {
		aux = (Node*)malloc(sizeof(Node));
		if (aux == NULL) {
			succ = false;
			break;
		}
		strcpy(aux->val, auxFile.val);
		aux->next = NULL;
		*h = InsertNode(aux, *h);
	}

	fclose(fp);
	fp = NULL;
	return succ;
}

/*
Carrega informação de Ficheiro
*/
Node *Load(Node *h, char* fileName) {
	FILE *fp;
	fp = fopen(fileName, "rb");
	if (fp == NULL) return NULL;

	//limpar lista
	//if(h!=NULL) DeleteAll(h);
	h = NULL;

	//ler e construir lista	
	Node *aux;
	NodeFile auxFile;

	while (fread(&auxFile, sizeof(NodeFile), 1, fp)!= 0) {
		aux = (Node*)malloc(sizeof(Node));
		if (aux == NULL) {
			break;
		}
		strcpy(aux->val, auxFile.val);
		aux->next = NULL;
		h = InsertNode(aux, h);
	}

	fclose(fp);
	fp = NULL;
	return h;
}

// =============================== AUXILIARES ===============================

/*
Cria uma nova pessoa. Alocação de memória feito no exterior
*/
void NewPersoII(Node *p, char *val) {
	strcpy(p->val,val);
	p->next = NULL;
}

/*
Cria uma nova pessoa. Tudo feito  no interior
*/
NodePtr NewNode(char *val) {
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	strcpy(p->val,val);
	p->next = NULL;
	return p;
}

/*
Mostra Pessoa
*/
void ShowNode(NodePtr p) {
	printf("\Valor= %s\n", p->val);
	//printf("Rua=%s\n", p->morada.rua);
}

void ShowNodeII(Node p) {
	printf("\nNumero= %s\n", p.val);
	//printf("Rua=%s\n", p.morada.rua);
}
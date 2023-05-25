//-----------------------------------------------------------------------
// <copyright file="Hashing.c" company="IPCA">
//     Copyright IPCA. All rights reserved.
// </copyright>
// <date>2023</date>
// <author></author>
// <email></email>
// <version></version>
// <desc>Biblioteca para manipular Tabelas de Hash</desc>
//-----------------------------------------------------------------------

//Tabela de Hash : array de heads de listas!

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


#pragma region ABORDAGEM I

#define SIZE 100

/*
Inicia a Tabela de Hash
*/
void IniciaHash(Node *ht[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		ht[i] = NULL;
	}
}

/*
Função de Hashing baseada em texto
*/
int HashFunction(char* palavra) {
	//h1: Primeiro caracter da string é "key"
	//int res = ((int)palavra[0]) % MAX;			//(int)palavra[0]-'A')
	//return res;

	//h2
	//int res = ToUpperCase(palavra[0]) % MAX;
	//return res;

	//h3;	
	int tot = 0;
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		tot += (int)palavra[i];
	}
	return (tot%MAX);
}

/*
Hashing dependente de chaves do tipo numérico
*/
int HashFunctionII(int val) {
	if (val > 0)
		return (val % MAX);
	return 0;
}

#pragma region Inserir na Hash

/*
Insere elemento na Tabela de Hash
*/
Node** InsertValHash(char* autor, Node** ht) {

	//Cria nova celula para a lista
	Node* item = (struct Node*)malloc(sizeof(struct Node));
	strcpy(item->val,autor);
	item->next = NULL;

	//get the hash 
	//int pos = Hash(item->val);

	//Assume-se definir sempre no início da lista
	*ht = InsertNodeHashInicio(item, ht);
	return *ht;
}


/**
 * @brief Insere elemento na Tabela de Hash....insere no início
 *	Não se está a verificar se já existe, i.e,
 *	Não gere colisões!
 * 
 * @param item
 * @param ht
 * @return 
 * @author lufer
 *
 */
Node ** InsertNodeHashInicio(Node* item, Node *ht[]) {

	//index = valor da Hash
	int pos = HashFunction(item->val);

	item->next = ht[pos];	
	ht[pos] = item;

	return *ht;
}

/**
 * @brief Insere na Hash e controla sucesso.
 * 
 * @param item
 * @param ht
 * @return 
 * @author lufer
 *
 */
bool InsertNodeHashInicioII(Node* item, Node *ht[]) {

	//index 
	int pos = HashFunction(item->val);

	item->next = ht[pos];
	ht[pos] = item;

	return true;
}

/*
Insere elemento na Tabela de Hash
Insere ordenado na Lista
*/
Node ** InsertNodeHash(Node* item, Node *ht[]) {

	//get the hash 
	int pos = HashFunction(item->val);

	Node *h = ht[pos];
	if (h == NULL)			//é  o primeiro nodo da lista
		ht[pos] = item;
	else                    //gerir colisões
	{
		ht[pos] = InsertNode(item, ht[pos]);
	}
	return *ht;
}

/*
Array alterado diretamente via parametros
Insere ordenado na Lista
*/

void InsertNodeHashVoid(Node* item, Node *ht[]) {

	//get the hash 
	int pos = HashFunction(item->val);

	Node *h = ht[pos];
	if (h == NULL)			//é  o primeiro nodo da lista
		ht[pos] = item;
	else                    //gerir colisões
	{
		ht[pos] = InsertNode(item, ht[pos]);
	}
	//não necessita de return!
}

/*
Array alterado diretamente via parametros
Insere ordenado na Lista
*/
bool InsertNodeHashBool(Node* item, Node **ht) {

	//get the hash 
	int pos = HashFunction(item->val);

	Node *h = ht[pos];
	if (h == NULL)			//é  o primeiro nodo da lista
		ht[pos] = item;
	else                    //gerir colisões
	{
		ht[pos] = InsertNode(item, ht[pos]);
	}
	return true;
}

#pragma endregion

/*
Procura elemento na Hash
*/
Node* FindNode(char *val, Node *ht[]) {
	int pos = HashFunction(val);
	if (ht[pos] == NULL) return NULL;
	return (Find(val, ht[pos]));
}

/*
Limpa Tabela de Hash
*/
Node ** Cleanup(Node *ht[]) {
	int i;
	Node *np, *t;
	for (i = 0; i < MAX; i++) {
		if (ht[i] != NULL) {
			np = ht[i];		//np é head da lista
			DeleteAll(np);	//Apaga lista
			ht[i] = NULL;
		}
	}
	return *ht;
}

/*
Mostra a Hash
*/
void ShowHash(Node *ht[])
{
	for (int i = 0; i < MAX; i++) {
		if (ht[i] != NULL)
		{
			printf("Index: %d \t", i);
			ShowList(ht[i]);
		}
	}
}

bool SaveHash(Node** h, char* fileName) {
	/*FILE* fp = fopen(fileName, "wb");
	if (fp == NULL) return false;
	*/
	bool r = false;
	if (h == NULL) return false;
	for (int i = 0; i < MAX; i++) {
		if (h[i] != NULL)
		{
			r = SaveList(h[i],fileName);
		}
	}
	//fclose(fp);
	return true;
}

Node** GetHash(char* fileName, int size) {
	FILE* fp = fopen(fileName, "rb");
	if (!fp) return NULL;
	Node** hash;
	hash = (Node**)malloc(size * sizeof(Node*));
	if (!hash) return NULL;
	NodeFile aux;
	Node auxNode;
	while (fread(&aux, 1, sizeof(aux), fp)) {
		strcpy(auxNode.val, aux.val);
		auxNode.next = NULL;
		*hash = InsertNodeHash(&auxNode, hash);
	}
	fclose(fp);
	return hash;
}

/*
DESAFIOS
*/

//Delete(int v) : apaga a lista de colisões da chave v
//Length(int v) : comprimento da lista de colisões da chave v
//MaxLength() : maior comprimento das listas de colisões
//MinLength() : menor comprimento das listas de colisões
//Media() : média do comprimento das listas
//Gravar
//Carregar



// ===================== AUXILIARES ===================

	/*
	* Converte caracter em minúsculas
	*/
int ToUpperCase(char c) {
	/* subtair 21 ao valor ASCII atual do caracter(exemplo:'a'-'A'=32)
	*/
	if ('a' <= c && c <= 'z')
		return c - 32;
	else
		return (int)c;
}

/*
Mostra Tabela de ASCII
*/
void AsciiTable() {
	for (int i = 0; i < 255; i++) {
		printf("%x %d %c\n", i, i, i);
	}
}

#pragma end region


#pragma region ABORDAGEM_II

// =================== OUTRA Abordagem ================
//
//	HashTable é uma struct com uma Hash e um número de índexes
//ou
static HashTable ht;

/*
Outra hipótese: size==MAX!?
*/
void IniciaHashTable(int size) {
	int i;
	ht.max = size;
	ht.tabela = (struct Node*) malloc(sizeof(Node)*size);
	for (i = 0; i < size; i++) {
		ht.tabela[i] = NULL;
	}
}


/*
Insere no início com Hash Table global...
*/
void InsertSimple(char*val, Node* hashTable[])
{
	int h;
	h = HashFunction(val);

	Node *novo = (Node*)malloc(sizeof(Node));
	strcpy(novo->val,val);
	novo->next = hashTable[h];
	hashTable[h] = novo;
}

/*
Derivação da Função de Hash
*/
int HashFunctionIII(char *v, int M) {
	int i, h = v[0];
	for (i = 1; v[i] != '\0'; i++)
		h = (h * 251 + v[i]) % M;
	return h;
}

// ========================= EXERCÍCIO ==========================
// ================ Hash Com Listas Duplamente Ligadas ===============
// Livro / Palavras

typedef char *string;

typedef struct Palavra {
	string palavra;
	int    ocorrencias;
	struct Palavra *next;
	struct Palavra *prev;
} Palavra;


/*
Insere nodo de forma ordenada!
*/
//Palavra *InserePalavra(Palavra *head, string palavra) { 
Palavra *InserePalavra(Palavra *head, char *palavra) {
	Palavra *aux = head;

	if (head == NULL) //se a lista estiver vazia
	{	// aloca espaço para a nova palavra e inicializa parametros
		Palavra *word = (Palavra*)malloc(sizeof(Palavra));
		strcpy(word->palavra, palavra);
		word->ocorrencias = 1;
		return head = word;// return : sai do metodo
	}
	else
	{
		while (aux->next != NULL || strcmp(aux->palavra, palavra) < 0) //procura onde inserir				
		{
			aux = aux->next;
		}
		// verificar se a palavra já existe
		if (strcmp(aux->palavra, palavra) == 0) {
			aux->ocorrencias++;
			return head;
		}
		// return ou else
		// isto pode ficar no seu proprio metodo
		Palavra *word = (Palavra*)malloc(sizeof(Palavra));
		word->palavra = palavra;
		word->ocorrencias = 1;

		//insere no início
		if (aux == head) {
			//Após o primeiro elemento
			if (strcmp(aux->palavra, palavra) < 0) {
				word->next = aux->next;
				aux->next = word;
				word->prev = aux;
			}
			else {
				// Adicionar na frente
				word->next = aux;
				aux->prev = word;
				head = palavra; // aux = palavra
			}
		}
		else {
			//Inserir no meio ou no fim
			// No fim
			if (!aux->next) { // aux->next != NULL
				aux->next = word;
				word->prev = aux;
				word->next = NULL;
			}
			else {
				// caso esteja entre outras palavras
				word->next = aux->next;
				word->prev = aux;
				aux->next->prev = word;
				aux->next = palavra;
			}
		}
	}
	return head;
}

/*
Remove ocorrência
*/
Palavra *RemovePalavra(Palavra *head, char *palavra) {
	if (!head) return NULL;
	Palavra *aux = head;
	while (aux->next != NULL && strcmp(palavra, aux->palavra) > 0) {
		aux = aux->next;
	}
	// elemento a eleminar no inicio
	if (aux == head) {
		aux->ocorrencias--;
		if (aux->ocorrencias == 0) {
			aux->next->prev = NULL;
			head = aux->next;
			free(aux);
		}
	}
	else {
		aux->ocorrencias--;
		if (aux->ocorrencias == 0) { // verificar se funciona a remocao na ultima posicão
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
			free(aux);
		}

	}
}

#pragma end region



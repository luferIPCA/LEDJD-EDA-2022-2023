/*****************************************************************//**
 * @file   hash.h
 * @brief  Tabelas de Hash
 * Index->Lista Ligada
 * @author lufer
 * @date   May 2023
 *********************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include "Listas.h"

#pragma warning (disable: 4996)
#ifndef HASH
#define HASH
#define MAX 31 /* tamanho da tabela de hashing -> recomenda-se que seja primo */

//h1: Tabela de Hash
typedef struct HashTable {
	int max;
	struct Node** tabela;
	//ou
	//struct Node* tabela[MAX];
}HashTable;

//h1: Tabela de Hash
//static HashTable hash;		//declara uma instância de uma HashTable

//h2: Tabela de Hash
//static struct Node* hashTable[MAX];	


//Assinaturas de Métodos
//Funções de Hash
int HashFunction(char* palavra);
int HashFunctionII(int val);

//Manipular Hash
void IniciaHash(Node *ht[], int n);
Node **IniciaHashII(Node *ht[]);
Node ** InsertValHash(char* autor, Node *ht[]);
Node ** InsertNodeHash(Node *autor, Node *ht[]);
Node** InsertNodeHashInicio(Node* item, Node *ht[]);

void ShowHash(Node *ht[]);
NodePtr FindNode(char *val, Node *ht[]);
Node **Cleanup(Node *ht[]);
int HashFunctionIII(char* v, int M);

void InsertNodeHashVoid(Node* item, Node **ht);
bool InsertNodeHashBool(Node* item, Node **ht);
bool InsertNodeHashInicioII(Node* item, Node *ht[]);

//Auxiliares
void AsciiTable();
int ToUpperCase(char c);

//Preservar Hash em Ficheiro
bool SaveHash(Node** h, char* fileName);
Node** GetHash(char* fileName, int size);


#endif // !HASH


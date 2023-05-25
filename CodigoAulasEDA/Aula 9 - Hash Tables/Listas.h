//-----------------------------------------------------------------------
// <copyright file="All.h" company="IPCA">
//     Copyright IPCA. All rights reserved.
// </copyright>
// <date>2023</date>
// <author>lufer</author>
// <email>lufer@ipca.pt</email>
// <version></version>
// <desc>Biblioteca para Manipular Listas Ligadas Simples</desc>
//-----------------------------------------------------------------------
#include <stdbool.h>
#ifndef HEADER
#define HEADER


#pragma warning (disable: 4996)
#define N 20

//typedef  enum boolean { false, true }   boolean;

//
//typedef struct Obra {
//	char* titulo;
//	int ano;
//	struct Obre *next;
//}Obra, *ObraPtr;


//nodo da lista
typedef struct Node
{
	char val[N];			
	struct Node* next;
} Node, *NodePtr;

typedef struct NodeFile
{
	char val[N];
} NodeFile;
	

NodePtr InsertNode(NodePtr np, NodePtr h);
int Count(NodePtr h);
NodePtr DeleteNode(char *val, NodePtr h);
NodePtr Find(char *val, NodePtr h);
bool Exist(char *val, NodePtr h);
bool SaveList(NodePtr h, char* f);
Node *Load(Node *h, char* fileName);
bool LoadControled(Node** h, char* fileName);
void DeleteAll(NodePtr h);
NodePtr NewNode(char *val);
void ShowList(NodePtr h);								
void ShowNode(NodePtr p);
void ShowNodeII(Node p);
void NewNodeII(Node *p, char *val);

#endif
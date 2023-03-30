/*****************************************************************//**
 * @file   Duplas.h
 * @brief  Listas Ligadas Duplas
 * 
 * @author lufer
 * @date   May 2022
 *********************************************************************/

#include <time.h>		//manipular datas

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

struct Nodo {
	int v;
	struct Nodo *next;
	struct Nodo *prev;
};

typedef struct Nodo Nodo, *NodoPtr;
typedef enum Boolean {false, true} Boolean;

#pragma region ASSINATURA METODOS
//Assinatura de Métodos

NodoPtr Inicia(NodoPtr h);					//inicia Lista

NodoPtr NovoNodo(int x);					//cria novo nodo

NodoPtr InsereNodo(NodoPtr h, NodoPtr n);	//insere ordenado

#pragma region SEARCH
NodoPtr Search(Nodo *h, Nodo *n);			//procura elemento
NodoPtr SearchII(Nodo *h, int valor);		//procura elemento através do valor
NodoPtr SearchIII(Nodo *h, Nodo valor);

Nodo SearchIV(Nodo *h, Nodo valor);
Nodo SearchV(Nodo *h, Nodo *valor);
Nodo SearchVI(Nodo *h, int valor);

Boolean SearchVII(Nodo *h, Nodo valor);
Boolean SearchVIII(Nodo *h, Nodo *valor);
Boolean SearchVIX(Nodo *h, int valor);
#pragma endregion


Boolean SaveAll(Nodo *h);					//preservar dados em ficheiro

Boolean SaveSome(Nodo *h, int vIni, int vFim);	//grave apenas alguns ???????

Nodo *Load();								//carregra dados do ficheiro

void ShowAll(Nodo *h);						//mostra Lista 
void ShowNode(Nodo *n);						//mostra Nodo

NodoPtr SubLista(NodoPtr h, int vIni, int vFim);	//gera sub-lista ?????

NodoPtr Remove(NodoPtr *h, int num);		//remove nodo

NodoPtr RemoveII(Nodo *h, int num);		//remove nodo ?????
#pragma endregion

#pragma region ListaSimples->Lista Dupla

typedef struct NodoSimples NodoSimples, *NodoSimplesPtr;

typedef struct NodoSimples {
	int v;
	time_t data;			//data de criação do jogo
	//ou
	//struct tm data;		//data de criação do jogo
	NodoSimples *next;
};


NodoSimplesPtr GeraListaLigadaSimples(NodoPtr h);	//????
NodoPtr GeraListaLigadaDupla(NodoSimplesPtr h);		//????
#pragma endregion

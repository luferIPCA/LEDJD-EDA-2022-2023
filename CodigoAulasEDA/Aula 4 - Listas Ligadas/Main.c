/*
author: lufer
Desc: Structs e Apontadores
Lista Ligadas Simples
*/
#include <stdio.h>
#include <locale.h>
#include "Dados.h"

#define MAX 10

int main() {

	setlocale(LC_ALL, "Portuguese");

	LeDadosCSV("Jogos.csv");

	

	Jogo j1 = {12,"jogo 1",'A'};
	Jogo j2 = { 13,"jogo 2",'A'};
	Jogo j3 = { 14,"jogo 3",'T' };

	//Aponta para in�cio da estrutura
	JogosListaPtr head=NULL;
	head = FileCSV2Lista("Jogos.csv");
	MostraLista(head);

	head = InsereJogoInicio(head, &j1);
	MostraLista(head);

	head = InsereJogoOrdenado(head, &j2);
	head = InsereJogoInicio(head, &j3);

	printf("\nJogos existentes:\n");
	MostraLista(head);

	bool aux = gravarJogoBinario("dados.bin", head);

	head = NULL;

	head = lerJogosBinario("dados.bin");
	printf("\nLido do Ficheiro:\n");
	MostraLista(head);

	JogosListaPtr nodo = ProcuraJogo(head, 12);
	printf("\nPesquisa:\n");
	MostraJogo(nodo);

	head = RemoveJogo(head, 13);
	printf("\nAp�s Remover:\n");
	MostraLista(head);



	printf("\nConstru��o a partir de Array:\n");
	Jogo jogos[3] = {j1,j2,j3};
	head = NULL;
	head = ConsList(jogos, 3);
	MostraLista(head);



	printf("\nConstru��o Recursiva a partir de Array:\n");
	head = NULL;
	head = ConsListRec(jogos, 3);
	MostraLista(head);



	printf("\nConstru��o Recursiva II a partir de Array:\n");
	head = NULL;
	head = ConsListRecII(jogos,0, 3);
	MostraLista(head);


	int xxx = ContaJogos(head, 'A');
	printf("\nExistem %d do tipo %c\n", xxx,'A');

	getche();
	return 1;
}

//Outros m�todos:
//
//Constroi Lista a partir de Array
//Constroi Lista Recursiva a partir de um array
//Insere no in�cio da Lista
//Insere no fim da lista
//Insere de forma ordenada
//Contar n�mero de nodos da Lista
//Eliminar nodo da lista
//Eliminar todos	
//Procurar nodo

//TPC: N�o remover em definitivo...criar um ficheiro de log??

//Exercicio: 
//Implementar Fun��o que Conta n�mero de Jogos de um 
//determinado tipo

//Enviar para lufer@ipca.pt
//assunto: exercicio_PP2_n�meroAluno
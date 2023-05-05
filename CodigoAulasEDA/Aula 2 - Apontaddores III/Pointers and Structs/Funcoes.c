/*
Fun��es para manipular arrays de structs
lufer@ipca.pt
Ver:
https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
http://www.geeksforgeeks.org/sorting-algorithms/#Basic
*/

#include "Dados.h"

/*
Apresenta informa��o sobre cada jogo
*/
void mostraJogos(Jogo jogos[], int t) {
	for (int i = 0; i < t; i++) {
		printf("Jogo= %d | Nome= %s | Ano: %d\n", jogos[i].cod, jogos[i].nome, jogos[i].data.ano);
	}
}

/*
Insere novo jogo numa determinada posi��o
Jogo passa por par�metro
*/
int InsereJogo(Jogo* jogos[], Jogo j, int pos) {
	//0� Verificar se o array tem capacidade e a posi��o � v�lida
	if (pos < 0 || pos > MAX) return -1;

	// Ver se o jogo j� existe
	if (ExisteJogo(jogos, j.cod, MAX) == false) return -1;

	//1� criar espa�o em memoria para um jogo
	jogos[pos] = (Jogo*) malloc(sizeof(Jogo));

	//2� coloco array a apontar para esse espa�o
	jogos[pos]->cod = j.cod;
	strcpy(jogos[pos]->nome,j.nome);
	jogos[pos]->data = j.data;
	pos++;
	return pos;
}

/*
Insere novo jogo.
Endere�o de jogo passa por par�metro
*/
int InsereJogoII(Jogo* jogos[], Jogo *j, int pos) {

	jogos[pos] = j;

	pos++;
	return pos;
}
/*
Verifica se determinado jogo existe
*/
bool ExisteJogo(Jogo* jogos[], int cod, int n) {
	for (int i = 0; i < n; i++) {
		if (jogos[i]->cod == cod) 
			return true;
	}
	return false;
}
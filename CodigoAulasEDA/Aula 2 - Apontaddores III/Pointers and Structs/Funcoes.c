/*
Funções para manipular arrays de structs
lufer@ipca.pt
Ver:
https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
http://www.geeksforgeeks.org/sorting-algorithms/#Basic
*/

#include "Dados.h"

/*
Apresenta informação sobre cada jogo
*/
void mostraJogos(Jogo jogos[], int t) {
	for (int i = 0; i < t; i++) {
		printf("Jogo= %d | Nome= %s | Ano: %d\n", jogos[i].cod, jogos[i].nome, jogos[i].data.ano);
	}
}

/*
Insere novo jogo numa determinada posição
Jogo passa por parâmetro
*/
int InsereJogo(Jogo* jogos[], Jogo j, int pos) {
	//0º Verificar se o array tem capacidade e a posição é válida
	if (pos < 0 || pos > MAX) return -1;

	// Ver se o jogo já existe
	if (ExisteJogo(jogos, j.cod, MAX) == false) return -1;

	//1º criar espaço em memoria para um jogo
	jogos[pos] = (Jogo*) malloc(sizeof(Jogo));

	//2ª coloco array a apontar para esse espaço
	jogos[pos]->cod = j.cod;
	strcpy(jogos[pos]->nome,j.nome);
	jogos[pos]->data = j.data;
	pos++;
	return pos;
}

/*
Insere novo jogo.
Endereço de jogo passa por parâmetro
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
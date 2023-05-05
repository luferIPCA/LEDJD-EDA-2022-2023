
#include <stdio.h>
#include "Dados.h"



int main() {

	//Jogo jogos[MAX];

	//jogos[0].cod = 12;

	//mostraJogos(jogos, 1);
	
	//Array de Jogos
	Jogo arrayJogos[MAX] = { { 12,"XXX",'T' } };
	mostraJogos(arrayJogos, 1);
	

	//Array de Apontadores para jogos
	Jogo* jogos[MAX];

	int numJogos = 0;

	Jogo j = { 12,"Jogo",'A',{12,12,2017} };

	//numJogos = InsereJogo(jogos, j, numJogos);

	numJogos = InsereJogo(jogos, j, numJogos);

	numJogos = InsereJogoII(jogos, &j, numJogos);

	return 1;
}
/*
* author: lufer
* email: lufer@ipca.pt
* date: 06.03.2022
* desc: Apontadores
*/

#include "Dados.h"

int* changeValue(const int* p) {
	//*p = *p + 1;		//não é permitido pois é const
	return p;
}

int* Maior(int* p, int* q) {
	if (*p > *q) return p;
	return q;
}

/**
* Verifica se determinado existe num array
* @param [in] n
* @param [out] p	//posição do array
*/
bool ExisteValorPosicao(int v[], int n, int valor, int* pos) {

	for (int i = 0; i < n; i++) {
		if (v[i] == valor) {
			*pos = i;		//posição onde existe
			return (true);
		}
	}
	*pos = -1;				//posição errada!
	return (false);
}

/**
* Analisar!!!! Qual o problema?
*/
int get(int* ptr) {
	int a = 10;
	ptr = &a;
	return 0;
}

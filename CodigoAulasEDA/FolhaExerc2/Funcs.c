/*****************************************************************//**
 * @file   Funcs.c
 * @brief  Implementação das Funcões
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#include <stdbool.h>

/**
 * @brief .
 * 
 * @param x
 * @param y
 * @return 
 * @author lufer
 *
 */
int Soma(int x, int y) {
	return x + y;

}

/**
 * @brief .
 * 
 * @param p
 * @param q
 * @return 
 * @author lufer
 *
 */
int SomaApontadores(int* p, int* q) {
	return (*p + *q);
}

/**
 * @brief Soma dois valores com resultado via parâmetro.
 * 
 * @param p
 * @param q
 * @param r
 * @author lufer
 *
 */
void SomaApontadoresII(int* p, int* q, int* r) {
	*r = *p + *q;
}

#pragma region NOTA

typedef struct Aux {
	int x;
	int y;
}Aux;

Aux Troca(int x, int y) {
	int k = x;
	x = y;
	y = k;
	Aux a;
	a.x = x; a.y = y;
	return a;
}

#pragma endregion

/**
 * @brief Calcula o maior de dois valores inteiros.
 * 
 * @param x
 * @param y
 * @return 
 * @author lufer
 *
 */
int Maior(int x, int y) {

	/*if (x > y) return x;
	return y;*/
	
	return (x > y ? x : y);
}

/**
 * @brief Calcula o Maior entre dois valores passados como
 * endereços.
 * 
 * @param x
 * @param y
 * @return 
 * @author lufer
 *
 */
int MaiorII(int* x, int* y) {
	return(*x > *y ? *x : *y);
}


bool MaiorIII(int* p, int* q, int* r) {
	if (*p== *q) 
		return false;
	*r = (*p > *q) ? *q : *p;
	return(true);
}
/**
 * @brief Apresenta no ecrã os valores de um array de inteiros.
 * 
 * @param valores
 * @param size
 * @return 
 * @author lufer
 *
 */
bool MostraArray(int valores[], int size) {
	if (size <= 0) return false;

	for (int i = 0; i < size; i++)
		printf("valores[%d]=%d\n", i, valores[i]);

	return true;
}

/**
 * @brief Apresenta no ecrã os valores de um array 
 * de inteiros.
 *
 * @param valores
 * @param size
 * @return
 * @author lufer
 *
 */
bool MostraArrayII(int *valores, int size) {
	if (size <= 0) return false;

	for (int i = 0; i < size; i++)
		printf("valores[%d]=%d\n", i, *(valores+i));

	return true;
}

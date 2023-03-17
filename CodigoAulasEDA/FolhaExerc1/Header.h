/*****************************************************************//**
 * @file   Header.h
 * @brief  Assinatura das funções...
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#include <stdbool.h>

#ifndef A
#define A

/**
 * Calcula a.
 */
int Soma(int x, int y);
/**
 * .
 */
int SomaApontadores(int* p, int* q);
void SomaApontadoresII(int* p, int* q, int* r);
int MaiorII(int* x, int* y);
bool MaiorIII(int* p, int* q, int* r);

bool MostraArray(int valores[], int size);
bool MostraArrayII(int* valores, int size);

#endif // !A



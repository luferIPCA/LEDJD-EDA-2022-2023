/*
	author: oribeiro & lufer
	Estruturas de dados
*/
#ifndef DADOS2
#define DADOS2
 

#include <stdio.h>
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

/* defini��o do tipo de dados TDATA  */

typedef struct DATA {
               int dia, mes, ano; }  DATA;



void escreverData(DATA data) ;
/* ler uma data do teclado (stdin) */
DATA lerData() ;

/* ---------------------------------------
    fun��es com c�lculos acerca datas
   --------------------------------------- */
/* fun��o que dada uma data calcula o n�mero
   de anos que j� passaram  */
// int calcularIdade(int dia, int mes, int ano) {
int calcularIdade(DATA data) ;

#endif //

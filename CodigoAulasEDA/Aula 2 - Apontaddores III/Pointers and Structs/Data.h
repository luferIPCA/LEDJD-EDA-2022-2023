/*
	author: oribeiro & lufer
	Estruturas de dados
*/
#ifndef DADOS2
#define DADOS2
 

#include <stdio.h>
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

/* definição do tipo de dados TDATA  */

typedef struct DATA {
               int dia, mes, ano; }  DATA;



void escreverData(DATA data) ;
/* ler uma data do teclado (stdin) */
DATA lerData() ;

/* ---------------------------------------
    funções com cálculos acerca datas
   --------------------------------------- */
/* função que dada uma data calcula o número
   de anos que já passaram  */
// int calcularIdade(int dia, int mes, int ano) {
int calcularIdade(DATA data) ;

#endif //

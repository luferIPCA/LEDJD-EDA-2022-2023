/*****************************************************************//**
 * @file   Var.h
 * @brief  
 * 
 * @author lufer
 * @date   December 2022
 *********************************************************************/
#pragma once

#include <stdio.h>
#include <stdbool.h>

#ifndef VAR
#define VAR

#define MAXCHAR 1000
#define MAXVALS 100
#define MAXDATE 20

typedef struct Valor {
    //date,open,high,low,close,volume
    char data[MAXDATE];
    double open;
    double high;
    double low;
    double close;
    double volume;
}Valor;

bool LeDadosCSV(char fileName[]);
#endif // !VAR

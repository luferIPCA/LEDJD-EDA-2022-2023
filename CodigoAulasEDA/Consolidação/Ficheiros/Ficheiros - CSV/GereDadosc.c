/*****************************************************************//**
 * @file   GereDadosc.c
 * @brief  
 * 
 * @author lufer
 * @date   December 2022
 *********************************************************************/

#include "Var.h"
#pragma warning (disable: 4996)

bool LeDadosCSV(char fileName[] )
{
    char row[MAXCHAR];
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("Problemas na leitura do ficheiro");
        return false;
    }

    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        printf("Row: %s", row);
    }

    fclose(fp);
    return true;
}

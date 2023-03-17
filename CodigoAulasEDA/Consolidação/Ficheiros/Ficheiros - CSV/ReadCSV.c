/*****************************************************************//**
 * @file   ReadCSV.c
 * @brief  
 *		Read a line->L
 *		Split L by,
 * @author lufer
 * @date   December 2022
 *********************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>


#pragma warning (disable: 4996)

#include "Var.h"

int main() {

    FILE* fp;
    char row[MAXCHAR];  //auxiliar para guardar cada linha do ficheiro
    char* token;

    //Estrutura para guardar dados do ficheiro
    Valor valores[MAXVALS];
    int totalValores = 0;

#pragma region LerCSV

    bool b = LeDadosCSV("Dados.csv");
    
#pragma endregion

#pragma region AnalisaCSV

    Valor aux;

    fp = fopen("Dados.csv", "r");
    if (fp == NULL) {
        perror("Problemas na leitura do ficheiro");
        exit(-1);
    }
    int rowNumber = 0;
    while (fgets(row, MAXCHAR, fp)!=NULL)   //ou feof(fp) != true)
    {
        //printf("Row: %s", row);   //Debug
        if (rowNumber == 0)         //primeira linha com Column Headers
        {
            rowNumber++;
            continue;
        }

        token = strtok(row, ",");   //separador ","
        
        int t = 0;
        while (token != NULL)
        {
            printf("Token: %s\n", token);
            switch (t) {
            case 0:
                strcpy(aux.data, token);
                break;
            case 1: 
                aux.high = atof(token); 
                break;
            case 2: 
                aux.low = atof(token);
                break;

            case 3: 
                aux.open = atof(token);
                break;
            case 4: 
                aux.volume = atof(token);
                break;
            }
            t++;
            token = strtok(NULL, ",");     
        }
        //guarda o aux no array
        valores[totalValores] = aux;
        totalValores++;
    }
    fclose(fp);

#pragma endregion

    return 0;
}





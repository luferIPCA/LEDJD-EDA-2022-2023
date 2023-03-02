/*
	Name:
	Author: oribeiro & lufer
	Date: 2020
	Description:
		- Manipula��o de Ficheiros

	Ver: 
	https://www.tutorialspoint.com/cprogramming/c_file_io.htm
	https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
	https://www.tutorialspoint.com/c_standard_library/c_function_fputs.htm
*/
#include <stdio.h>
#include <locale.h>

#define TAM 40			//define uma "constante"

// --------------declara��o ou assinatura das fun��es locais --------------

/* fun��o que dada uma frase devolve o seu tamanho
   (o mesmo que strlen). */
int tamanho(char *frase);

/* fun��o que dada uma frase txtIn coloque a sua inversa em txtOut;
   devolve: 0 no caso de sucesso;
            -1 caso contr�rio   */
int inversa(char *txtIn, char *txtOut);


//-------------------------------------------------------------------------

// fun��o principal
int main3() {
	setlocale(LC_ALL, "Portuguese");

	// declara��o e inicializa��o de vari�veis
	char s[TAM]; //= "O Benfica � o maior!";
	char fraseInv[TAM];
    int tam = 0;
    int resultado = 0;
	int c;							//auxiliar
    FILE *fIn = NULL;					//handler de ficheiro de entrada
	FILE *fOut = NULL;	 				//handler de ficheiro de sa�da

	// dados de entrada
	//fIn = fopen("c:\\temp\\frases.txt", "r"); // abrir frases.txt em modo leitura
	//se houve algum problema...
	fIn = fopen("frases.txt", "r");
	if (fIn == NULL){
		perror("Erro ao abrir o ficheiro\n");
		getche();
		//return(-1);
	}
	
	//Ficheiro de sa�da
	fOut = fopen("frasesInversas.txt", "w"); // abrir frases.txt em modo escrita
	//fOut = fopen("copiaFrases.txt", "a"); // abrir copiaFrases.txt em modo escrita
	//testar se tudo correu bem na cria��o do file


	c = 1;
	//Analisar conte�do do ficheiro
	while (fgets(s, TAM, fIn ) != NULL ) // stdin );
	  {
		//colocar "finalizador de string";
		if (s[tamanho(s)-1]=='\n') 			
			s[tamanho(s)-1] = '\0';

		printf("frase %d : | %s | \n", c++,s);

		tam = tamanho(s);
		printf(" Tamanho: %d \n", tam);

		resultado = inversa(s, fraseInv);

		if (resultado == -1)
				printf("ERRO: um dos argumentos � nulo! \n");
		else
				printf("frase inicial: %s Frase inversa: |%s| \n", s, fraseInv);
		
		fputs(fraseInv, fOut);
		fputs("\n", fOut);

		//ou

		//fprintf(fOut,"%s\n", fraseInv);
	  }
	
	fclose(fIn);
	fclose(fOut);
	getche();
	return 0;
}

// defini��o das fun��es
/* fun��o que dada uma frase devolve o seu tamanho
   (o mesmo que strlen). */
int tamanho(char *frase){
    int i; // contador

    i = 0;
    while (frase[i] != '\0')
    {
        i = i + 1;
    }
    return i;
}


/* fun��o que dada uma frase txtIn coloque a sua inversa em txtOut;
   devolve: 0 no caso de sucesso;
            -1 caso contr�rio   */
int inversa(char *txtIn, char *txtOut){
    int i; // contador
    int k;

    if (txtIn == NULL || txtOut == NULL)
        return -1; // indica��o de erro;

    i = tamanho(txtIn) - 1; // o �ndice do �ltimo caracter da string
    k=0;
    while (i>=0)
    {
        // guardar a inversa
        txtOut[ k ] = txtIn[i];
        // --------
        i = i - 1;
        k = k + 1;
    }
    txtOut[k] = '\0';// colocar o terminador no final de txtOut
    return 0;
}






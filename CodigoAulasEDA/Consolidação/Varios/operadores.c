/**
 * @file operadores.c
 * @author lufer (lufer@ipca.pt)
 * @brief Operadores em C
 * @version 0.1
 * @date 2020-10-30
 * 
 * Arithmetic Operators 
 * Relational Operators 
 * Logical Operators 
 * Bitwise Operators 
 * Assignment Operators 
 * Misc Operators
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>

int main(){

    int x, y;
    char c;

    //=
    x=10;
    y=7;
    c=x*2;
    c='C';

    //><!===

    printf("x>y : %d\n", x>y);
    printf("x!=y: %d\n", x!=y);
    
    //++x
    printf("X= %d - %d - %d\n", x, x++, ++x);

    printf("C= %c - %c - %c\n",c, c++, --c);

}
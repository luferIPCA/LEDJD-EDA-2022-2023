/**
 * @file variables.c
 * @author lufer (lufer@ipca.pt)
 * @brief Manipulação de variaveis e operadores
 * @version 0.1
 * @date 2020-10-29
 * @see https://www.tutorialspoint.com/cprogramming/c_variables.htm
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

// Variable declaration:
extern int a, b;
extern int c;
extern float f;

int main () {

   /* variable definition: */
   int a, b;
   int c;
   float f;
   int r;
 
   /* actual initialization */
   a = 10;
   b = 20;
  
   c = a + b;
   printf("%d + %d = %d \n", a,b,c);

   f = 70.0/3.0;
   printf("value of f : %4.3f \n", f);

   r= 70.0/3.0;

   printf("resto = %d \n", r);
 
   return 0;
}
/**
 * @file output.c
 * @author lufer (lufer@ipca.pt)
 * @brief printf function
 * @version 0.1
 * @date 2020-10-29
 * @see http://www.cplusplus.com/reference/cstdio/printf/
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>

int main()
{
   //printf
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");

   //strings
   puts("Uma string..");
   printf("%s","Outra string...\n");

   //characters
   putchar(127);    
   putchar(10);   //nl
   putchar(65);
   putchar(10);   //nl
   return 0;
}
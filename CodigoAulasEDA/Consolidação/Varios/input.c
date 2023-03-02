/**
 * @file input.c
 * @author lufer (lufer@ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2020-10-29
 * @see http://www.cplusplus.com/reference/cstdio/scanf/
 * @copyright Copyright (c)  2020
 * 
 */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str [80];
  int i;
  
  char* nome;

  //scanf
  printf ("Enter your family name: ");
  scanf ("%79s",str);  
  printf ("Enter your age: ");
  scanf ("%d",&i);
  printf ("Mr. %s , %d years old.\n",str,i);
  printf ("Enter a hexadecimal number: ");
  scanf ("%x",&i);
  printf ("You have entered %#x (%d).\n",i,i);

  scanf("%[^\n]s", str); 

  //getchar
  fflush(stdin);    //limpar buffer
  char aux = getchar();
  putchar(aux);
  putchar(10);
  
  //gets
  fflush(stdin);    //limpar buffer
  printf("Nome: ");
  gets(nome);
  puts(nome);
  return 0;
}
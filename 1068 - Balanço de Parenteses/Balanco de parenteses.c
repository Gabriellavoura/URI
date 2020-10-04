#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int i;
  char array[1001];
  int balanco = 0;
  while(scanf("%s", array) != EOF)
  {
    // Primeiramente fazemos as verificações mais simples:
    if(array[0] == ')' || array[strlen(array)] == '(')  // Se começa com ) ja esta incorreto.
    {
      printf("incorrect\n");
      continue;
    }

      for(i = 0; i < strlen(array); i++) // Enquanto não for o fim
      {
        if(array[i] == '(' )
        {
          balanco = balanco + 1;
        }
        else if(array[i] == ')' )
        {
          balanco = balanco - 1;
        }
        if(balanco < 0){
          printf("incorrect\n");
          balanco = 0;
          break;
        }
        if((balanco == 0) && (i == (strlen(array)-1))) // Se esta no ultimo loop, verifica o balanco
        {
          printf("correct\n");
        }
        if((balanco != 0) && (i == (strlen(array)-1))){
          printf("incorrect\n");
          balanco = 0;
        }
      }
    }
}

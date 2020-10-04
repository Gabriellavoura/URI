#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{

  struct nodo *esq;
  char nome[11];
  int abates;
  struct nodo * dir;
}Nodo;

int busca(Nodo *raizM, char nome[]){

	if (!raizM)
		return 1;

	if (strcmp(raizM->nome, nome) == 0)
		return 0;

	if (strcmp(raizM->nome, nome) > 0)
		busca(raizM->esq, nome);
	else
		busca(raizM->dir, nome);
}

void infixa(Nodo *raizA, Nodo *raizM){

  if(raizA && raizM){
    infixa(raizA->esq, raizM);
    if (busca(raizM, raizA->nome))
      printf("%s %d\n", raizA->nome, raizA->abates);
    infixa(raizA->dir,raizM);
  }
}

void insere(Nodo **raiz, char nome[], int flag){

    Nodo *nodo = NULL;
    Nodo *novoNodo = malloc(sizeof(Nodo));

    novoNodo->esq = NULL;
    strcpy(novoNodo->nome, nome);
    if( flag == 1)
    {
      novoNodo->abates = 1;
    }
    else{
      novoNodo->abates = 0;
    }
    novoNodo->dir = NULL;


  if(*raiz == NULL){

    *raiz = novoNodo;
    //printf("Inseriu RAIZ!\n");
  }
  else{

    nodo = *raiz;

    while(nodo != NULL){

      if(strcmp(nodo->nome, nome) > 0){

        if(nodo->esq == NULL){
          nodo->esq = novoNodo;
          //printf("INSERINDO %s NA ESQUERDA DE %s || raiz: %s\n", novoNodo->nome, nodo->nome, (*raiz)->nome);
          nodo = NULL;

          break;
        }
        nodo = nodo->esq;
      }
      else if(strcmp(nodo->nome, nome) < 0){

        if(nodo->dir == NULL){
          nodo->dir = novoNodo;
          //printf("INSERINDO %s NA DIREITA DE %s || raiz: %s\n", novoNodo->nome, nodo->nome, (*raiz)->nome);
          nodo = NULL;
          break;
        }
        nodo = nodo->dir;
      }
      else{
        nodo->abates++;
        nodo = NULL;
        break;
      }
    }
  }
}


int main()
{
    char assassino[27], mortos[27];
    int i, j, flag = 0;

    Nodo * raizA = malloc(sizeof(Nodo));
    Nodo * raizM = malloc(sizeof(Nodo));
    raizA = NULL;
    raizM = NULL;

    while(scanf("%s %s", assassino, mortos) != EOF){
      insere(&raizA, assassino, 1);
      insere(&raizM, mortos, 0);

    }

    printf("HALL OF MURDERERS\n");
    infixa(raizA, raizM);
    free(raizA);
    return 0;
}

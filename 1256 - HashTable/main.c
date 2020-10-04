#include <stdio.h>
#include <stdlib.h>

int chave = 0, tamanho = 0;

//Nodo que o nodo da hash aponta.
typedef struct nodoA{
  int dado;
  struct nodoA * prox;
}NodoA;

// Nodo da lista principal ( tamanho da hashTable)
typedef struct nodoB{
  int indice;
  NodoA * proxLista;
  struct nodoB *prox;
}NodoB;

// Estrutura que marca o inicio e fim da tabela.
typedef struct hashTable{
  NodoB* inicio;
  NodoB* fim;
  int qtd;
}HashTable;

int hash(int valor){
  return valor % tamanho;
}

void push(HashTable * hashT, int indice, int valor){

  // Insere primeiro elementos
  if( hashT->inicio == NULL && valor == 0){

      NodoB * novo = malloc(sizeof(NodoB));

      novo->indice = indice;
      novo->proxLista = NULL;
      novo->prox = NULL;


      if(novo != NULL){ // Se conseguiu alocar:
          hashT->inicio = hashT->fim = novo;
          hashT->qtd++;
      }
      else{
        //printf("Nao foi possivel alocar memoria!\n");
      }
  }

  else if(valor == 0){

    NodoB * novo = malloc(sizeof(NodoB));

    novo->indice = indice;
    novo->proxLista = NULL;
    novo->prox = NULL;

    // Insere elemento no final da lista:
    hashT->fim->prox = novo;
    hashT->fim = hashT->fim->prox;
    hashT->qtd++;
  }

  else{

    int j, hashValor;

    // Controla o indice da lista:
    NodoB * tmp = malloc(sizeof(NodoB));

    tmp = hashT->inicio;

    hashValor = hash(valor);

    for(j = 0; j <= hashValor; j++){

      if( j == hashValor){
        // cria nodo
        NodoA * novo = malloc(sizeof(NodoA));

        novo->dado = valor;
        novo->prox = NULL;

        if(tmp->proxLista == NULL){
          tmp->proxLista = novo;
        }
        else{
            NodoA *tmp2 = malloc(sizeof(NodoA));
            tmp2 = tmp->proxLista;

            while( tmp2->prox != NULL){
              tmp2 = tmp2->prox;
            }
            tmp2->prox = novo;
        }
      }
      tmp= tmp->prox;
    }
    valor = 0;
  }

}

HashTable * CriaLista(int size){

  int i = 0;

  HashTable * hashT = malloc(sizeof(HashTable));

  if( hashT != NULL ){ // Se conseguiu alocar:
    hashT->inicio = hashT->fim = NULL;
    hashT->qtd = 0;

    // Cria a lista principal com n elementos.
    for(i = 0; i < size; i ++){
      push(hashT, i, 0);
    }
    return hashT;
  }
  else{
    return 0;
  }
}

void imprimeTable(HashTable * hashT){

  NodoB * tmp = malloc(sizeof(NodoB));

  tmp = hashT->inicio;

  while(tmp != NULL){

    printf("%d -> ", tmp->indice);

      if(tmp->proxLista == NULL){
        printf("\\\n");
      }

      else{
        NodoA * aux = malloc(sizeof(NodoA));

        aux = tmp->proxLista;

        while(aux != NULL){

          printf("%d -> ", aux->dado);

          aux = aux->prox;
        }
        printf("\\\n");

      }
    tmp = tmp->prox;
  }
}

int main()
{
    int valor, i, casos;
    scanf("%d", &casos);

    while(casos){

      //printf("Digite o tamanho da lista seguido da chave:\n");
      scanf("%d %d", &tamanho, &chave);

      HashTable * hashT = CriaLista(tamanho);

      for(i = 0 ; i < chave; i ++){
        scanf("%d", &valor);
        push(hashT, 0, valor);
      }

      imprimeTable(hashT);

      if((casos-1) != 0){
       printf("\n");
      }

      casos --;

    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000007

typedef struct node{
	unsigned long long int valor;
	struct node *prox;
}Nodo;

typedef struct queue{
	Nodo * inicio;
	Nodo * fim;
	int qtd;
}Fila;


Fila * InicializaFila(){
	Fila * f = (Fila *)malloc(sizeof(Fila));

	if( f != NULL ){
		f->inicio = f->fim = NULL;
		f->qtd = 0;
	}
	else{
		printf("Nao foi possivel inicializar a fila\n");
	}

	return f;
}

int push(Fila *f, unsigned long long int valor){

	Nodo * novo = (Nodo*)malloc(sizeof(Nodo));

	if( novo != NULL){
		// Se a fila esta vazia
		if( f->inicio == NULL){

			novo->valor = valor;
			novo->prox = NULL;
			f->inicio = f->fim = novo;
			f->qtd++;

			return 1;
		}
		else{
			novo->valor = valor;
			novo->prox = NULL;

			f->fim->prox = novo;
			f->fim = novo;
			f->qtd++;
			return 1;
		}
	}
	else{
		printf("Nao foi possivel criar um novo nodo.\n");
		return 0;
	}
	return 1;
}

void pop(Fila *f){
	// Primeiro verifica se esta vazio:
	if( f->inicio == NULL){
		printf("Fila Vazia, nao ha o que remover!\n");
		return;
	}
	else{
		Nodo * tmp = (Nodo *)malloc(sizeof(Nodo));

		if( tmp != NULL){
			tmp = f->inicio;
			f->inicio = f->inicio->prox;
			free(tmp);
			f->qtd--;
			return;
		}
		else{
			printf("Nao foi possivel criar um tmp.\n");
			return;
		}
	}
}

int peekInicio(Fila *f){

	if(f->inicio == NULL){
		return 0;
	}
	else{
		return f->inicio->valor;
	}
}

unsigned long long int peekFim(Fila *f){
	if(f->inicio == NULL){
		return 0;
	}
	else{
		return ((f->fim->valor) % MOD);
	}
}

void imprimeFila(Fila *f){
	Nodo * tmp = (Nodo *)malloc(sizeof(Nodo));

	tmp = f->inicio;

	printf("Fila:\n[");

	while(tmp != NULL){
		printf("%d ",tmp->valor);
		tmp = tmp->prox;
	}
	printf("]\n");
}

unsigned long long int retornaElementosFila(Fila *f){

  Nodo * tmp = (Nodo *)malloc(sizeof(Nodo));

	tmp = f->inicio;
  unsigned long long int soma = 0;
	while(tmp != NULL){
		soma = soma + tmp->valor;
		tmp = tmp->prox;
	}
	return ((soma) % MOD);
}

int peekN(Fila *f, int n){
  Nodo * tmp = (Nodo *)malloc(sizeof(Nodo));

  int i;
  for(i = 0, tmp = f->inicio;  i <= n; tmp = tmp->prox, i++){
		if( i == n-1) return tmp->valor;
	}
}

void geraKesimo(Fila *f, unsigned long long int inicio, unsigned long long int fim){

  Nodo * tmp = (Nodo *)malloc(sizeof(Nodo));
  unsigned long long int i;

  for( i = 0; i < inicio; i++){
    push(f, i);
  }
  for(i = inicio; i < fim ; i++){
    // soma os elementos e adiciona no final:
    push(f, retornaElementosFila(f));
    pop(f);

  }
}

int main(){

  int k = 0, n = 0, i = 0, soma = 0, tries;

  scanf("%d", &tries);

  while(tries--){

  //printf("Digite o valor de K e N\n");
  scanf("%d %d", &k, &n);

  Fila *f = InicializaFila();
  // Inicia a fila com 0 e 1.
  push(f,0);
  push(f,1);

  if (k < 2 || n < 1) {
    continue;
  }

  if( f->qtd < k ){
    // Gera os K primeiros elementos
    for(i = 0; i < k-2; i++){

      push(f, retornaElementosFila(f));
    }
  }

  if( n <= k){
    printf("%d\n", (n-1) % MOD);
  }
  else if( n > k ){
      // Preenche de k em k
      Fila * f2 = InicializaFila();
      geraKesimo(f2,k,n);
      printf("%lld\n", peekFim(f2));

      free(f2);
  }
  free(f);

  }


	return 0;
}




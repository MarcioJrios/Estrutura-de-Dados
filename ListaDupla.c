#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct _produto{
	int cod;
	char nome[20];
	float preco;
} TpProduto;

typedef struct _nodo{
	TpProduto info;
	struct _nodo *prox;
	struct _nodo *prev;
} TpNodo;

typedef struct _lista{
	int nItens;
	TpNodo *first;
	TpNodo *last;
} TpLista;

TpLista *push(TpLista *u){
	TpNodo *v = (TpNodo *)malloc(sizeof(TpNodo));
	if(u->nItens == 0){
		u->first = v;
	}else{
	v->prox=u->first;
	u->first->prev = v;
}
	system("clear");
	__fpurge(stdin);
	printf("Codigo do produto: ");
	scanf("%d", &v->info.cod);
	getchar();
	printf("Nome do produto: ");
	scanf("%[^\n]s", v->info.nome);
	getchar();
	printf("Preco do produto: R$ ");
	scanf("%f", &v->info.preco);
	system("clear");
	if(u->nItens == 0){
		u->first = v;
		u->last = v;
		u->first->prox = NULL;
		u->first->prev = NULL;
		u->last->prox = NULL;
		u->last->prev = NULL;
	}else{
		u->first = v;
		u->first->prev = NULL;
	}
	u->nItens++;
	return u;
}
void *pop(TpLista *u){
	int n;
	if(u->nItens == 0){
		printf("Lista Vazia!\n");
		return u;
	}
	printf("Digite o codigo do produto que deseja remover: \n");
	scanf("%d", &n);
	TpNodo *aux2;
	TpLista aux1;
	aux1 = *u;
	if(u->first->prox == NULL && u->first->prev == NULL && u->first->info.cod == n){	
		u->first = NULL;
		u->nItens=0;
		printf("Elemento de codigo [%d] removido com sucesso!\n", n);
		return u;
	}else{
		while(u->first != NULL){
			
			if(u->first->info.cod == n){
				if(u->first->prev == NULL){
					u->first = u->first->prox;
					u->first->prev = NULL;
					printf("Elemento de codigo [%d] removido com sucesso!\n", n);
					u->nItens--;
					return u;
				}else if(u->first->prox == NULL){
						u->first = u->first->prev;
						u->first->prox = NULL;
						while(u->first->prev != NULL){
							u->first = u->first->prev;
						}
						printf("Elemento de codigo [%d] removido com sucesso!\n", n);
						u->nItens--;
						return u;
					}else{
						aux2 = u->first;
						u->first = u->first->prox;
						u->first->prev = aux2->prev;
						u->first = u->first->prev;
						u->first->prox = aux2->prox;
						while(u->first->prev != NULL){
							u->first = u->first->prev;
						}
						printf("Elemento de codigo [%d] removido com sucesso!\n", n);
						u->nItens--;
						free(aux2);
						return u;
					}
				}
			aux1 = *u;
			u->first = u->first->prox;
		}
				
	}
	if(u->first == NULL && u->nItens > 0)
		*u = aux1;
	while(u->first->prev != NULL){
		u->first = u->first->prev;
		}
	printf("Elemento de código %d não encontrado", n);
	system("sleep 1");
	return u;
}

TpLista *display(TpLista *u){
	system("clear");
	TpLista aux = *u;
	if(u->nItens == 0){
			puts("Lista Vazia");
			return u;
	}
	for(; u->first !=NULL;u->first = u->first->prox){
		printf("Codigo: %d\n", (u->first->info.cod));
		printf("Nome: %s\nPreco: R$ %.2f\n", (u->first->info.nome), (u->first->info.preco));
	}
		*u = aux;
		return u;
}

int main(){
	int n;
	TpLista *u = (TpLista *)malloc(sizeof(TpLista));
	u->first = NULL;
	u->last = NULL;
	u->nItens = 0;
	do{
		puts("\t\tMENU\n");
		puts("1: Para inserir um produto na pilha;");
		puts("2: Para extrair um elemento da pilha;");
		puts("3: Para listar todos os campos dos elementos da pilha;");
		puts("0: Sair.\n");
		puts("Digite a opção desejada:");
		scanf("%d", &n);
		switch(n){
			case 1:
				u=push(u);
				u->nItens++;
				break;
				system("clear");
			case 2:
				system("clear");
				u=pop(u);
				break;
			case 3:
				u=display(u);
				puts("");
				break;
			case 0:
				system("clear");
				puts("Voce escolheu por sair!");
				break;
			default:
				puts("Opcao invalida!");
		}
	}while(n!=0);
	free(u);
	return 0;
}

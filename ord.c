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

TpLista *selectionSort(TpLista *u){
	system("clear");
	int i, j;
	if(u->nItens == 0){
		printf("Lista Vazia");
		return u;
	}else if(u->nItens == 1){
		printf("só um elemento na lista!");
		return u;
	}else{
	TpNodo *aux = (TpNodo *)malloc(sizeof(TpNodo));
	TpNodo *aux2 = (TpNodo *)malloc(sizeof(TpNodo));
	TpNodo *aux3 = (TpNodo *)malloc(sizeof(TpNodo));
	aux = u->last->prev;
	for(i = 0; i < u->nItens; u->last = u->last->prev, i++){
		for(j = i+1; j < u->nItens; aux = aux->prev, j++){
            puts("C\n");
			if(u->last->info.cod > aux->info.cod){
                if(u->nItens == 2){
                    aux2 = u->last;
                    u->last = aux;
                    aux = aux2;
                    u->last->prev = aux2->prev;
                    aux->prox = u->last;
                    u->last->prox = NULL;
                    aux->prev = NULL;
                    u->first = aux;
                    return u;					//Ultima alteração
                    }
				else if(u->first->prev == NULL){
					if(aux->prox == NULL){
                        printf("A\n");
						aux2 = u->first;
						u->first = aux;
						aux = aux2;
						u->first->prox = aux2->prox;
						aux->prev = u->first;
						u->first->prev = NULL;
						aux->prox = NULL;
                        printf("E\n");
						}else{
                            printf("D\n");
							aux2 = u->first;
							aux3 = aux;
							u->first = aux;
							aux = aux2;
							u->first->prox = aux2->prox;
							u->first->prev = NULL;
							aux->prev = aux3->prev;
							aux->prox = aux3->prox;

 							}
					}else{
                        printf("F\n");
						aux2 = u->first;
						aux3 = aux;
						u->first = aux;
						aux = aux2;
						u->first->prox = aux2->prox;
						u->first->prev = aux2->prev;
						aux->prox = aux3->prox;
						aux->prev = aux3->prev;

					}
            }printf("%d", u->first->info.cod);
        }
	}
	while(u->first->prev != NULL){
		u->first = u->first->prev;
		}
		return u;
  }
}

/*void *insertionSort(TpLista *u){
	system("clear");
	int i;
	TpNodo *atual, *ant, *prox;
	atual = u->last;
	ant = u->last->prox;
	prox = u->last->prev;
}*/

void *insertionSort(TpLista *u){
	system("clear");
	int i, j, n = u->nItens;
	TpNodo atual, ant, *aux, *aux2;
	u->first = u->first->prox;
	for(i = 1, j=i; i < n; i++){
		puts("H\n");
		for(; j<i ; j++){
			u->first = u->first->prox;
			puts("J");
		}

		puts("P");
		j=i;
		while(u->first->prev != NULL && u->first->prev->info.cod > u->first->info.cod){
			puts("A\n");
			atual = *u->first;
			ant = *u->first->prev;
			if(u->nItens == 2){
				u->first->prox = u->first->prev;
				u->first->prev = NULL;
				u->first->prox->prox = NULL;
				u->first->prox->prev = u->first;
				u->last = u->first->prox;
				j--;
			}else if(u->first->prox == NULL){
				puts("B\n");
				u->first->prev = ant.prev;
				u->first->prox = atual.prev;
				u->first->prev->prox = u->first;
				aux = u->first;
				u->first = u->first->prox;
				u->first->prox = NULL;
				u->first->prev = aux;
				u->last = u->first;
				u->first = u->first->prev;
				j--;
			}else if(u->first->prev->prev == NULL){
				
				puts("C\n");
				u->first->prox = u->first->prev;
				u->first->prev = NULL;
				aux = u->first;
				u->first = u->first->prox;
				puts("G");
				u->first->prev = aux;
				u->first->prox = atual.prox;
				aux2 = u->first;
				u->first->prox->prev = aux2;
				u->first = u->first->prev;
				j--;
				}else{
					puts("C\n");
					u->first->prox = u->first->prev;
					u->first->prev = ant.prev;
					u->first->prev->prox = u->first;
					aux = u->first;
					u->first = u->first->prox;
					puts("G");
					u->first->prev = aux;
					u->first->prox = atual.prox;
					aux2 = u->first;
					u->first->prox->prev = aux2;
					u->first = u->first->prev;
					j--;
				}

				/*puts("C\n");
				u->first->prox = atual->prev;
				u->first->prev = ant->prev;
				aux = u->first;
				u->first = u->first->prev;
				u->first->prox = aux;
				u->first = u->first->prox;
				aux = u->first;
				u->first = u->first->prox;
				u->first->prox = proximo;
				u->first->prev = aux;
				aux = u->first;
				u->first = u->first->prox;
				u->first->prev = aux;
				/*if(u->first->prev != NULL){
					u->first = u->first->prev;
					u->first->prox = aux;
					u->first = u->first->prox;
				}//
				u->first = u->first->prev;*/
		}
		//Ultima alteração         *Arrumar o first


	}
	while(u->first->prev != NULL){
		u->first = u->first->prev;
		}
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
        puts("4: Para ordenar por Insertion Sort;");
		puts("0: Sair.\n");
		puts("Digite a opção desejada:");
		scanf("%d", &n);
		switch(n){
			case 1:
				u=push(u);
				break;
			case 2:
				system("clear");
				u=pop(u);
				break;
			case 3:
				u=display(u);
				puts("");
				break;
            		case 4:
                		system("clear");
                		u=insertionSort(u);
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

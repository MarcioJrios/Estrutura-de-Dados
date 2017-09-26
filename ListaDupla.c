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

TpNodo *push(TpLista *u){
	TpNodo *v = (TpNodo *)malloc(sizeof(TpNodo));
	v->prox=u.first;
	v->prev=NULL;
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
	if(nItens == 0){
		u.first = v;
		u.last = v;
	else{
		first = v;}
	return v;

void *pop(TpLista *u){
	int i, n;
	printf("Digite o codigo do produto que deseja remover: \n");
	scanf("%d", &n);
	TpLista *ant, *aux;
	if(u.first == NULL && u.last == NULL){
		printf("Não encontrado!\n");
	for(aux = u ; aux.last != NULL && aux.first != NULL; aux = aux->prox){
		if(aux->info.cod == n){
			break;
		}
		ant = aux;
	}
	if(aux == u){
		u = u->prox;
		printf("Elemento de codigo [%d] removido com sucesso!\n", n);
	}
	else{
		ant->prox = aux->prox;
		printf("Elemento de codigo [%d] removido com sucesso!\n", n);
	}
	free(aux);
	system("sleep 2");
	return u;
}

int main(){
	int n;
	TpLista *u;
	u.first = NULL;
	u.last = NULL;
	u.nItens;
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
				break;
				system("clear");
			case 2:
				system("clear");
				u=pop(u);
				break;
			case 3:
				display(u);
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

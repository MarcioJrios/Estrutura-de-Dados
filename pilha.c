#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 50

typedef struct _produto{//criação de uma struct tipo produto
	int cod;
	char nome[TAM];
	float preco;
}tp_produto;
typedef struct _pilha{//criação de uma struct tipo pilha
	tp_produto *info;
	int topo;
}tp_pilha;

int main(){
	int n, i, b;
	scanf("%d", &b);
	tp_pilha *pilha = (tp_pilha*)malloc(sizeof(tp_pilha));
	pilha->topo=-1;
	pilha->info = (tp_produto *)malloc(b * sizeof(tp_produto));
	do{
		puts("\t\tMENU\n");
		puts("1- Inserir um elemento na pilha;");
		puts("2- Extrair um elemento da pilha;");
		puts("3- Mostra os valores da pilha;");
		puts("0- Sair.\n");
		printf("Digite o numero correspondente a opcao: ");
		scanf("%d", &n);
		switch(n){
			case 1:
				system("clear");
				if (pilha->topo < b-1){
					pilha->topo++;
					scanf("%d", &(pilha->info+pilha->topo)->cod);
					scanf("%s", (pilha->info+pilha->topo)->nome);
					scanf("%f", &(pilha->info+pilha->topo)->preco);
					system("clear");
				}
				else
					puts("A pilha esta cheia!!!");
				break;
				system("clear");
			case 2:
				system("clear");
				if (pilha->topo > -1){
					pilha->topo--;
				}
				else
					puts("A pilha esta vazia!!!");
				break;
			case 3:
				system("clear");
				for(i=pilha->topo;i>=0;i--){
					printf("Posicao %d: %d\n", i, *(pilha->info->cod));
				}
				puts("");
				break;
			case 0:
				system("clear");
				puts("Voce escolheu por sair! Ate nunca mais!!!");
				break;
			default:
				puts("Opcao invalida!");
		}
	}while(n!=0);
	free(pilha);
	return 0;
}

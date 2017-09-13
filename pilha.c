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
	puts("Digite quantos produtos deseja cadastrar:");
	scanf("%d", &b);
	tp_pilha *pilha = (tp_pilha*)malloc(sizeof(tp_pilha));
	pilha->topo=-1;
	pilha->info = (tp_produto *)malloc(b * sizeof(tp_produto));
	do{
		puts("\t\tMENU\n");
		puts("1- Inserir um elemento na pilha;");
		puts("2- Remover um elemento da pilha;");
		puts("3- Exibir elementos da pilha;");
		puts("0- Sair.\n");
		printf("Digite o numero correspondente a opção: ");
		scanf("%d", &n);
		switch(n){
			case 1:
				system("clear");
				if (pilha->topo < b-1){
					__fpurge(stdin);
					puts("Insira o codigo do produto:");
					scanf("%d", &(pilha->info+pilha->topo+1)->cod);
					puts("Insira o nome do produto:");
					scanf("%s", (pilha->info+pilha->topo+1)->nome);
					puts("Insira o preco do produto:");
					scanf("%f", &(pilha->info+pilha->topo+1)->preco);
					pilha->topo++;
					system("clear");
				}
				else
					puts("A pilha esta cheia!");
				break;
				system("clear");
			case 2:
				system("clear");
				if (pilha->topo > -1){
					pilha->topo--;
				}
				else
					puts("A pilha esta vazia!");
				break;
			case 3:
				system("clear");
				for(i=pilha->topo;i>=0;i--){
					printf("Produto %d:\n Codigo: %d\n", i+1, ((pilha->info+i)->cod));
					printf("Nome: %s\n Preco: %f\n", ((pilha->info+i)->nome), ((pilha->info+i)->preco));
				}
				puts("");
				break;
			case 0:
				system("clear");
				break;
			default:
				puts("Opcao invalida!");
		}
	}while(n!=0);
	free(pilha);
}

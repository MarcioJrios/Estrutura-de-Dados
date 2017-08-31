#include<stdio.h>
#include<stdlib.h>

typedef struct{
char nome[50];
char endereco[100];
int matricula;
} estudante;

int main(){
	estudante *p = (estudante *)calloc(3, sizeof(estudante));
	int i;
	for(i = 0; i<3; i++){
		getchar();
		printf("%d nome:\n", i+1);
		fgets((p+i)->nome, 50, stdin);
		puts("endereco:");
		fgets((p+i)->endereco, 100, stdin);
		puts("matricula");
		scanf("%d", &(p+i)->matricula);
	}
	
	for(i = 0; i<3; i++){
		printf("%s\n", (p+i)->nome);
		printf("%s\n", (p+i)->endereco);
		printf("%d\n", (p+i)->matricula);
	}
	free(p);
}

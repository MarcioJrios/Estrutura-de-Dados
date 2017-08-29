#include<stdio.h>
#include<stdlib.h>

int main(){
	int *p = (int *)calloc(5, sizeof(int));
	if(!p){
		puts("Não foi possivel alocar memoria");
	}
	/* *p = 1;
	*(p+1) = 2;
	*(p+2) = 3;
	*(p+3) = 4;
	*(p+4) = 5;*/
	scanf("%d%d%d%d%d", p, p+1, p+2, p+3, p+4);
	printf("Posição 1: %p      Conteudo: %d\n", p, *(p));
	printf("Posição 2: %p      Conteudo: %d\n", p+1, *(p+1));
	printf("Posição 3: %p      Conteudo: %d\n", p+2, *(p+2));
	printf("Posição 4: %p      Conteudo: %d\n", p+3, *(p+3));
	printf("Posição 5: %p      Conteudo: %d\n", p+4, *(p+4));
}

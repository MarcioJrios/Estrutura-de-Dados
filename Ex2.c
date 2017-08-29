#include<stdio.h>
#include<stdlib.h>

typedef struct{
char nome[50];
char endereco[100];
int matricula;
} estudante;

int main(){
	estudante *p = (estudante *)calloc(3, sizeof(estudante));
	for(int i = 0; i<3; i++){
		

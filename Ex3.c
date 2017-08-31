#include<stdio.h>
#include<stdlib.h>

int main(){
	int n=5, h=2;
	int *p = (int *)calloc(n, sizeof(int));
	int i;
	int g;
	if(!p){
		puts("Não foi possivel alocar memoria");
	}
	for(i=0; i<=n; i++){
		if(i==n){
			int *pNew = realloc(p, (h*5) * sizeof(int));
			if(pNew)
				p = pNew;
			h++;
			n=n+5;
		}
		scanf("%d", p+i);
		if(*(p+i) == 0)
			break;
	}
	for(g = 0;g<i; g++){
		printf("Posição %d: %p      Conteudo: %d\n", g+1, p+g, *(p+g));
	}
	free(p);
}

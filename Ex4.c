#include<stdio.h>
#include<stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){
	int *v3 = (int *)calloc((n1+n2), sizeof(int));
	int h;
	for(h = 0; h<n1; h++){
		*(v3+h) = *(v1+h);
	}
	for(h = 0; h<n2; h++){
		*(v3+n1+h) = *(v2+h);
	}
	return(v3);
}
		

int main(){
	int v1[5]={10, 6, 4, 6, 3}, v2[4]={7, 5, 6, 8}, n1=5, n2=4;
	int *v3 = (int *)calloc((n1+n2), sizeof(int));
	int i;
	v3 = uniao(v1, n1, v2, n2);
	for(i = 0; i<n1+n2; i++){
		printf("%d", v3[i]);
	}
	printf("\n");
	free(v3);
}

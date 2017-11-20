#include <stdio.h>

void bubbleSort(int v[10]){
	int i, temp;
	for(i=0;i<5;i++){
		if(v[i]>v[i+1]){
			temp=v[i+1];
			v[i+1]=v[i];
			v[i]=temp;
			i=-1;
		}
	}
}

void inserir(int u[10]){
	int n, i = 0;
	while(i<10){
		printf("Digite o valor numero %d:   ", i+1);
		scanf("%d", &n);
		u[i] = n;
		i++;
	}
	bubbleSort(u);
}

void BBinaria(int u[10], int l, int h, int key){
    
    int mid;

    if (l > h)
    {
        printf("Valor nao encontrado!\n");
        return;
    }

    mid = (l + h) / 2;

    if (u[mid] == key)
    {
        printf("Valor encontrado!      posição: %d\n", mid);
	
    }

    else if (u[mid] > key)
    {
        BBinaria(u, l, mid - 1, key);
    }

    else if (u[mid] < key)
    {
        BBinaria(u, mid + 1, h, key);
    }
}

int main(){
	int u[10], key;
	int h;
	do{
		puts("Digite a opção desejada:");
		puts("1: Inserir valores na lista;");
		puts("2: Procurar um valor na lista;");
		puts("0: Sair;");
		scanf("%d", &h);
		
		switch(h){
			case 1:
				inserir(u);
				break;
			case 2:
				scanf("%d", &key);
				BBinaria(u, 0, 10, key);
				break;
			case 0:
				break;
			default:
				puts("Opção invalida");
				break;
			}
	}while(h != 0);
	
}

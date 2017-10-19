#include<stdio.h>

void bubbleSort(int v[6]){
	int i;
	for(i = 0; i<5; i++){
		if(v[i]>v[i+1]){
			int l = v[i+1];
			v[i+1] = v[i];
			v[i] = l;
			i = -1;
		}
	}
}

void selectionSort(int v[6]){
	int i, j;
	for(i = 0; i<6; i++){
		for(j = i+1; j<6; j++){
			if(v[j] < v[i]){
				int l = v[j];
				v[j] = v[i];
				v[i] = l;
			}
	}
}

void insertionSort(int v[6]){
	int i, j;
	for(i = 1; i<6 ; i++){
		for(j = i-1; j<6; j++){
			
}
int main(){
	int v[6] = {4 i, 2 j, 7, 3, 9, 1};
	



 

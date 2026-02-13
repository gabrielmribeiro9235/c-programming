#include <stdio.h>

int main(){
	
	int v[5];
	int i;
	
	for(i=0; i<5; i++){
		printf("Insira o dado %d:\n", i+1);
		scanf("%d", &v[i]);
	}
	printf("---------------------------\n");
	printf("Dados inseridos:\n");
	for(i=0; i<5; i++){
		printf("Dado %d: %d\n", i+1, v[i]);
	}
	
}

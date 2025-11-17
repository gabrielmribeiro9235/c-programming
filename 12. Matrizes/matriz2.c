#include <stdio.h>

int main(){
	int matriz[3][3];
	
	matriz[0][0] = 1;
	matriz[0][1] = 2;
	matriz[0][2] = 3;
	
	int i;
	
	for(i=0; i<3; i++){
		printf("%d ", matriz[0][i]);	
	}
	
	printf("\n");	
	
}

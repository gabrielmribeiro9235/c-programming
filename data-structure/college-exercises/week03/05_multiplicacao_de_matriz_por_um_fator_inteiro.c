#include <stdio.h>

int main() {
    int M[2][2], R[2][2], maior;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Insira o valor da linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &M[i][j]);
            if(i == 0 && j == 0) 
                maior = M[i][j];
            
            if(maior < M[i][j])
                maior = M[i][j];   
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            R[i][j] = M[i][j] * maior;
        }
    }

    printf("\nMaior valor inserido: %d\nMultiplicando todos os números inseridos por %d...\n\n", maior, maior);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Linha %d coluna %d: %d\n", i+1, j+1, R[i][j]);
        }
    }


    return 0;
}
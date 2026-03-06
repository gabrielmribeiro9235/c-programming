#include <stdio.h>

int main() {
    int mat[5][4], linha1[4], linha4[4], coluna0[5], coluna3[5];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Insira o valor da linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
            if(i == 1) 
                linha1[j] = mat[i][j];
            if(i == 4) 
                linha4[j] = mat[i][j];
        }
    }

    printf("\nMatriz original: \n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d\t\t", mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == 1) 
                mat[i][j] = linha4[j];
            if(i == 4) 
                mat[i][j] = linha1[j];
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {    
            if(j == 0) 
                coluna0[i] = mat[i][j];
            if(j == 3) 
                coluna3[i] = mat[i][j];
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            if(j == 0) 
                mat[i][j] = coluna3[i];
            if(j == 3) 
                mat[i][j] = coluna0[i];
        }
    }

    printf("\nMatriz nova: \n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d\t\t", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
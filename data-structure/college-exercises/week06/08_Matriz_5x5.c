#include <stdio.h>

void ler_matriz(int mat[5][5]);
void mostrar_matriz(int mat[5][5]);
void multiplicar_matriz(int mat[5][5], int num);

int main() {
    int mat[5][5];
    ler_matriz(mat);
    mostrar_matriz(mat);
    multiplicar_matriz(mat, 5);
    mostrar_matriz(mat);

    return 0;
}


void ler_matriz(int mat[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("Insira o valor da linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void mostrar_matriz(int mat[5][5]) {
    printf("------------------------------------------\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------------\n");
}

void multiplicar_matriz(int mat[5][5], int num) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            mat[i][j] *= num;
        }
    }
}
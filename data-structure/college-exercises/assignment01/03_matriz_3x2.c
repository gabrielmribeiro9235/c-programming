#include <stdio.h>

void ler_matriz(int mat[3][2]);
void exibir_matriz(int mat[3][2]);
int buscar_maior_elemento(int mat[3][2]);
void multiplicar_pelo_maior_elemento(int mat[3][2], int num);
void exibir_matriz_transposta(int mat[3][2]);

int main() {
    int matriz[3][2], maior;

    ler_matriz(matriz);

    exibir_matriz(matriz);

    maior = buscar_maior_elemento(matriz);
    printf("--------------------------------------------------\n");
    printf("Maior elemento da matriz: %d\n", maior);
    
    multiplicar_pelo_maior_elemento(matriz, maior);

    exibir_matriz_transposta(matriz);

    return 0;
}

void ler_matriz(int mat[3][2]) {
    printf("--------------------------------------------------\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Insira o elemento da linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void exibir_matriz(int mat[3][2]) {
    printf("--------------------------------------------------\n");
    printf("Matriz inserida:\n\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int buscar_maior_elemento(int mat[3][2]) {
    int maior_elemento;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            if(i == 0 && j == 0) {
                maior_elemento = mat[i][j];
                continue;
            }
            if(mat[i][j] > maior_elemento) 
                maior_elemento = mat[i][j];
        }
    }
    return maior_elemento;
}

void multiplicar_pelo_maior_elemento(int mat[3][2], int num) {
    printf("--------------------------------------------------\n");
    printf("Matriz multiplicada pelo seu maior elemento:\n\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d\t", mat[i][j] * num);
        }
        printf("\n");
    }
}

/* Se a ideia da função for apenas multiplicar e não mostrar, seria assim:
void multiplicar_pelo_maior_elemento(int mat[3][2], int num) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            mat[i][j] *= num;
        }
    }
} */

void exibir_matriz_transposta(int mat[3][2]) {
    printf("--------------------------------------------------\n");
    printf("Matriz transposta:\n\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d\t", mat[j][i]);
        }
        printf("\n");
    }
}
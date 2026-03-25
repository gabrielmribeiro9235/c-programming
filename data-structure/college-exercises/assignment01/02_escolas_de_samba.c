#include <stdio.h>
#define ESCOLAS 4
#define CATEGORIAS 3
#define JURADOS 2

int main() {
    float matriz[ESCOLAS][CATEGORIAS][JURADOS];

    for(int i = 0; i < ESCOLAS; i++) {
        printf("=========================================\n");
        printf("Escola %d\n", i+1);
        printf("=========================================\n");
        for(int j = 0; j < CATEGORIAS; j++) {
            printf("-----------------------------------------\n");
            printf("Categoria %d\n", j+1);
            for(int k = 0; k < JURADOS; k++) {
                printf("Nota do jurado %d: ", k+1);
                scanf("%f", &matriz[i][j][k]);
            }
        }
        printf("-----------------------------------------\n");
    }
    
    for(int i = 0; i < ESCOLAS; i++) {
        float soma = 0;
        for(int j = 0; j < CATEGORIAS; j++) {
            for(int k = 0; k < JURADOS; k++) {
                soma += matriz[i][j][k];
            }
        }
        printf("=========================================\n");
        printf("Soma dos pontos da Escola %d: %.1f\n", i+1, soma);
    }
    
    printf("=========================================\n");
    printf("-----------------------------------------\n");
    for(int i = 0; i < ESCOLAS; i++) {
        printf("=========================================\n");
        printf("Escola %d\n", i+1);
        printf("=========================================\n");
        for(int j = 0; j < CATEGORIAS; j++) {
            float soma = 0, media;
            for(int k = 0; k < JURADOS; k++) {
                soma += matriz[i][j][k];
            }
            media = soma / JURADOS;
            printf("-----------------------------------------\n");
            printf("Média da categoria %d: %.2f\n", j+1, media);
        }
        printf("-----------------------------------------\n");
    }

    return 0;
}
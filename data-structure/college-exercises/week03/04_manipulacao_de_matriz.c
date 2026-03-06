#include <stdio.h>

int main() {
    int mat[4][3], qnt_pares_por_linha[] = {0, 0, 0, 0};
    float media_coluna[] = {0, 0, 0};


    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Digite o elemento da linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
            media_coluna[j] += mat[i][j]; 
            if(mat[i][j] % 2 == 0)
                qnt_pares_por_linha[i]++;
        }
    }

    printf("\n");
    for(int i = 0; i < 4; i++) 
        printf("Na linha %d tem %d números pares\n", i+1, qnt_pares_por_linha[i]);
    printf("\n");
    for(int i = 0; i < 3; i++) {
        media_coluna[i] /= 4;
        printf("Média dos números da coluna %d: %.2f\n", i+1, media_coluna[i]);
    }

    return 0;
}
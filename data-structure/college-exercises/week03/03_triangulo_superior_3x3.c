#include <stdio.h>

int main() {
    int mat[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Digite o elemento da linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(j >= i)
                printf("%d ", mat[i][j]);
        }
    }


    return 0;
}
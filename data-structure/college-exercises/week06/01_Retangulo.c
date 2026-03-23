#include <stdio.h>

void retangulo(int largura, int altura, char simbolo);

int main() {
    retangulo(5, 3, '*');

    return 0;
}

void retangulo(int largura, int altura, char simbolo) {
    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {
            printf("%c", simbolo);
        }
        printf("\n");
    }
}
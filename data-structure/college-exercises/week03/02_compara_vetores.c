#include <stdio.h>
#define TAM 5

int main() {
    int vetor1[TAM], vetor2[TAM];
    
    for(int i = 0; i < 2 * TAM; i++) {
        if(i < TAM) {
            printf("Insira o valor %d do vetor 1: ", i+1);
            scanf("%d", &vetor1[i]);
        } else {
            printf("Insira o valor %d do vetor 2: ", i-TAM+1);
            scanf("%d", &vetor2[i-TAM]);
        }
    }
    
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            if(vetor1[i] == vetor2[j]) {
                printf("%d  ", vetor1[i]);
                break;
            }
        }
    }

    printf("\n");

    return 0;
}
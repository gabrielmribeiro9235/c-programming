#include <stdio.h>

#define TAM 5

float calcula_media(int arr[], int n, int *pmaior, int *pmenor);

int main() {
    int vetor[] = {7, 24, 2, 3, 4, 5};
    int maior = vetor[0], menor = vetor[0];
    
    float media = calcula_media(vetor, TAM, &maior, &menor);

    printf("Média dos valores: %.2f\n", media);
    printf("Maior valor      : %d\n", maior);
    printf("Menor valor      : %d\n", menor);

    return 0;
}

float calcula_media(int arr[], int n, int *pmaior, int *pmenor) {
    int soma = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > *pmaior)
            *pmaior = arr[i];
        if(arr[i] < *pmenor)
            *pmenor = arr[i];
        soma += arr[i];
    }

    return (float)soma / n;
}
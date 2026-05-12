#include <stdio.h>

int busca_maior(int *array, int n);

int main() {
    int vetor[] = {10, 5, 2, 50, 100, 200, 3};
    int maior = busca_maior(vetor, 7);
    printf("Maior valor: %d\n", maior);
}

int busca_maior(int *array, int n) {
    if(n == 1) 
        return array[0];
    int maior = busca_maior(array+1, n-1);
    return array[0] > maior ? array[0] : maior;
}
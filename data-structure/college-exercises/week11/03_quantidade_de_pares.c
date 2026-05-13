#include <stdio.h>

int conta_pares(int *array, int n);

int main() {
    int v[] = {1, 2, 10, 3, 7, 20, 2, 5, 20};
    int qnt_pares = conta_pares(v, sizeof(v)/sizeof(int));
    printf("Quantidade de pares: %d\n", qnt_pares);
    return 0;
}

int conta_pares(int *array, int n) {
    if(n == 0)
        return 0;
    return (array[0] % 2 == 0) + conta_pares(array + 1, n-1);
}
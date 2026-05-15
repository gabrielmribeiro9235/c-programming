#include <stdio.h>

int busca_binaria(int *arr, int n, int target);

int main() {
    int array[] = {1, 2, 5, 7, 17, 20, 33};
    int target = 17;
    int idx = busca_binaria(array, sizeof(array)/sizeof(int), target);
    if(idx == -1) {
        printf("%d não está no array\n", target);
        return 0;
    }
    printf("O índice de %d é %d", target, idx);
    return 0;
}

int busca_binaria(int *arr, int n, int target) {
    int inicio = 0, fim = n-1;
    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if(arr[meio] == target)
            return meio;
        if(arr[meio] < target) {
            inicio = meio + 1;
            continue;
        }
        fim = meio - 1;
    }
    return -1;
}
#include <stdio.h>
#include <stdlib.h>

int particionar(int *arr, int inicio, int fim);
void quick_sort(int *arr, int inicio, int fim);

int main() {
    int array[] = {10, 2, 3, 1, 20, 83, 6};
    quick_sort(array, 0, (sizeof(array) / sizeof(array[0])) - 1);
    for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        printf("%d\t", array[i]);
    }
    return 0;
}

void quick_sort(int *arr, int inicio, int fim) {
    if(inicio < fim) {
        int p = particionar(arr, inicio, fim);
        quick_sort(arr, inicio, p-1);
        quick_sort(arr, p + 1, fim);
    }
}

int particionar(int *arr, int inicio, int fim) {
    int pivo = arr[fim];
    int k = inicio;
    for(int i = inicio; i < fim; i++) {
        if(arr[i] < pivo) {
            int temp = arr[k];
            arr[k] = arr[i];
            arr[i] = temp;
            k++;
        }
    }
    int temp = arr[k];
    arr[k] = arr[fim];
    arr[fim] = temp;
    return k;
}
#include <stdio.h>

void merge_sort(int v[], int inicio, int fim);
void merge(int v[], int inicio, int meio, int fim);

int main() {
    int arr[] = {7, 1, 10, 30, 50};

    merge_sort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}

void merge_sort(int v[], int inicio, int fim) {
    if(inicio < fim) {
        int meio = (inicio + fim) / 2;

        merge_sort(v, inicio, meio);
        
        merge_sort(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}

void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int temp[fim - inicio + 1];

    while (i <= meio && j <= fim) {
        if(v[i] <= v[j]) 
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while(i <= meio)
        temp[k++] = v[i++];

    while(j <= fim)
        temp[k++] = v[j++];

    for(i = inicio, k = 0; i <= fim; i++, k++)
        v[i] = temp[k];
}
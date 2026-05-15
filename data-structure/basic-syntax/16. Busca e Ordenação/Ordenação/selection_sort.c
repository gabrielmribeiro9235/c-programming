#include <stdio.h>

void selection_sort(int *arr, int n);

int main() {
    int array[] = {8, 1, 5, 10, 12, 1};
    selection_sort(array, sizeof(array)/sizeof(int));
    for(int i = 0; i < sizeof(array) / sizeof(int); i++)
        printf("%d\t", array[i]);
    return 0;
}

void selection_sort(int *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int idx_menor = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[idx_menor])
                idx_menor = j;
        int temp = arr[i];
        arr[i] = arr[idx_menor];
        arr[idx_menor] = temp;
    }
}
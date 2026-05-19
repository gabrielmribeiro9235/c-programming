#include <stdio.h>

void insertion_sort(int *arr, int n);

int main() {
    int array[] = {3, 7, 1, 10, 20, 5};
    insertion_sort(array, sizeof(array) / sizeof(int));
    for(int i = 0; i < sizeof(array) / sizeof(int); i++) {
        printf("%d\t", array[i]);
    }
    return 0;
}

void insertion_sort(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
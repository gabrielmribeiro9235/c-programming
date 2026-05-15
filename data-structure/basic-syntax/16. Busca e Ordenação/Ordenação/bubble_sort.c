#include <stdio.h>

void bubble_sort(int *arr, int n);

int main() {
    int array[] = {2, 1, 10, 5, 8};
    bubble_sort(array, sizeof(array)/sizeof(int));
    for(int i = 0; i < (sizeof(array) / sizeof(int)); i++)
        printf("%d\t", array[i]);
    return 0;
}

void bubble_sort(int *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int flag = 0;
        for(int j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag++;
            }
        }
        if(flag == 0)
            break;
    }
}
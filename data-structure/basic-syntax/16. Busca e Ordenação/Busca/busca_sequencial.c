#include <stdio.h>

int busca_sequencia(int *arr, int n, int target);

int main() {
    int array[] = {1, 7, 5, 2, 20, 33, 17};
    int target = 17;
    int idx = busca_sequencia(array, sizeof(array)/sizeof(int), target);
    if(idx == -1) {
        printf("%d não está no array\n", target);
        return 0;
    }
    printf("O índice de %d é %d", target, idx);
    return 0;
}

int busca_sequencia(int *arr, int n, int target) {
    for(int i = 0; i < n; i++) 
        if(arr[i] == target) 
            return i;
    return -1;
}
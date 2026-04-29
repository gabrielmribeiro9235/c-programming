#include <stdio.h>
#include <stdlib.h>

int* array(int n);
void scan_array(int *ptr, int n);
void display_array(int *ptr, int n);

int main() {
    int n;
    printf("-------------------------------------\n");
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    printf("-------------------------------------\n");
    int *novo_array = array(n);
    if(!novo_array) {
        printf("Segmentação de memória falhou!\n");
        return 1;
    }
    scan_array(novo_array, n);
    printf("-------------------------------------\n");
    display_array(novo_array, n);

    free(novo_array);
    return 0;
}

int* array(int n) {
    return (int *)malloc(sizeof(int) * n);
}

void scan_array(int *ptr, int n) {
    for(int i = 0; i < n; i++) {
        printf("Insira a valor do elemento %d: ", i+1);
        scanf("%d", ptr);
        ptr++;
    }
}

void display_array(int *ptr, int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            printf("%d]\n", *ptr);
            continue;
        }
        printf("%d, ", *ptr);
        ptr++;
    }
}
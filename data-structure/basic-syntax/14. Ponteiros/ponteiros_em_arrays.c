#include <stdio.h>

int main() {
    int array[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    printf("Tamanho do array: %d\n", sizeof(array)/sizeof(array[0]));
    int *p = &array[0];
    printf("Posição 0 do array: %d\n", *p);
    p++;
    printf("Posição 1 do array: %d\n", *p);
    p++;
    printf("Posição 2 do array: %d\n", *p);
    p += 7;
    printf("Posição 9 do array: %d\n", *p);

    return 0;
}
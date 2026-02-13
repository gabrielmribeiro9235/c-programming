#include <stdio.h>

int main() {
    int a, b, c;
    printf("Insira o valor do lado 1: ");
    scanf("%d", &a);

    printf("Insira o valor do lado 2: ");
    scanf("%d", &b);

    printf("Insira o valor do lado 3: ");
    scanf("%d", &c);

    if((a + b > c) && (a + c > b) && (b + c > a)){
        if(a == b && b == c) {
            printf("Equilátero\n");
        } else if(a == b || a == c || b == c) {
            printf("Isósceles\n");
        } else {
            printf("Escaleno\n");
        }
    } else {
        printf("Não existe um triângulo de lados %d, %d e %d\n", a, b, c);
    }

    return 0;
}
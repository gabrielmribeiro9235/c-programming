#include <stdio.h>

int main() {
    float x, v1, v2, p, total;
    printf("Insira o valor de x (km): ");
    scanf("%f", &x);
    printf("Insira o valor de v1: R$ ");
    scanf("%f", &v1);
    printf("Insira o valor de v2: R$ ");
    scanf("%f", &v2);
    printf("Insira o percurso (km): ");
    scanf("%f", &p);

    if(p <= x) {
        total = p * v1;
    } else {
        total = p * v2;
    }
    
    printf("\nTotal: R$%.2f\n", total);

    return 0;
}
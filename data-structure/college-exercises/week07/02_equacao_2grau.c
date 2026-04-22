#include <stdio.h>
#include <math.h>

int resolver_equacao(double a, double b, double c, double *r1, double *r2);

int main() {
    double a, b, c, raiz1, raiz2;
    printf("Insira o coeficiente a: ");
    scanf("%lf", &a);
    printf("Insira o coeficiente b: ");
    scanf("%lf", &b);
    printf("Insira o coeficiente c: ");
    scanf("%lf", &c);
    int qnt_raizes = resolver_equacao(a, b, c, &raiz1, &raiz2);
    if(qnt_raizes == -1) {
        printf("\nA equação inserida não é do segundo grau\n");
        return 0;
    }
    if(qnt_raizes == 0) {
        printf("\nA equação não tem raízes reais!\n");
        return 0;
    }
    if(qnt_raizes == 1) {
        printf("\nA equação tem 1 raiz!\n");
        printf("Raiz: %.2f\n", raiz1);
        return 0;
    }
    printf("\nA equação tem 2 raízes!\n");
    printf("Raiz 1: %.2f\n", raiz1);
    printf("Raiz 2: %.2f\n", raiz2);
    return 0;
}

int resolver_equacao(double a, double b, double c, double *r1, double *r2) {
    if(a == 0)
        return -1;
    double delta = (b*b) - (4*a*c);
    if(delta < 0)
        return 0;
    if(delta == 0) {
        *r1 = -b / (2*a);
        return 1;
    }
    *r1 = (-b + sqrt(delta)) / (2*a);
    *r2 = (-b - sqrt(delta)) / (2*a);
    return 2;
}
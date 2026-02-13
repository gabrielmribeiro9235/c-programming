#include <stdio.h>

int main() {
    int minutos;
    float horas;

    printf("Insira o número de minutos: ");
    scanf("%d", &minutos);

    horas = (float)minutos / 60;
    printf("%d minutos equivalem a %.2f horas\n", minutos, horas);

    return 0;
}
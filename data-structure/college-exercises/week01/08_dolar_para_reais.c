#include <stdio.h>

int main() {
    float cotacao, dolares, reais;

    printf("Insira a cotação do dólar: R$ ");
    scanf("%f", &cotacao);

    printf("Insira o valor em dólar: US$ ");
    scanf("%f", &dolares);

    reais = dolares * cotacao;
    printf("US$ %.2f valem R$ %.2f\n", dolares, reais);

    return 0;
}
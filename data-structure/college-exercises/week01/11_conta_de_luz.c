#include <stdio.h>

int main() {
    float  salario_minimo, quilowatts_consumidos, valor_quilowatt, valor_conta;

    printf("Insira o valor do salário mínimo: R$ ");
    scanf("%f", &salario_minimo);

    printf("Insira quantos quilowatts foram consumidos: ");
    scanf("%f", &quilowatts_consumidos);

    valor_quilowatt = salario_minimo / 5;
    valor_conta = valor_quilowatt * quilowatts_consumidos;

    printf("Valor do quilowatt: R$ %.2f\n", valor_quilowatt);
    printf("Valor da conta: R$ %.2f\n", valor_conta);

    return 0;
}
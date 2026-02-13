#include <stdio.h>

int main() {
    float salario, pct, aumento, novo_salario;
    
    printf("Insira o salário: R$ ");
    scanf("%f", &salario);
    printf("Insira a porcentagem de aumento: ");
    scanf("%f", &pct);

    aumento = pct/100 * salario;
    novo_salario = salario + aumento;
    printf("\nAumento: R$ %.2f\n", aumento);
    printf("Novo salário: R$ %.2f\n", novo_salario);
    
    return 0;
}
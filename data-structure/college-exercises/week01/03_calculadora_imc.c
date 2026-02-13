#include <stdio.h>

int main() 
{
    float peso, altura, imc;

    printf("Insira o seu peso (kg): ");
    scanf("%f", &peso);
    
    printf("Insira a sua altura (m): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);
    printf("O seu IMC é: %.2f\n", imc);

    return 0;
}
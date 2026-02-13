#include <stdio.h>

int main() {
    float peso, altura, IMC;

    printf("Insira o seu peso (kg): ");
    scanf("%f", &peso);
    printf("Insira o seu altura (m): ");
    scanf("%f", &altura);

    IMC = peso / (altura * altura);
    printf("O seu IMC é: %.1f\n", IMC);
    if(IMC < 18.5) {
        printf("Você está abaixo do peso!\n");
    } else if(IMC <= 24.9) {
        printf("Você está no peso normal!\n");
    } else if(IMC <= 29.9) {
        printf("Você está acima do peso!\n");
    } else if(IMC <= 34.9) {
        printf("Você está com obesidade I!\n");
    } else if(IMC <= 39.9) {
        printf("Você está com obesidade II!\n");
    } else {
        printf("Você está com obesidade III!\n");        
    }
    
    
    return 0;
}
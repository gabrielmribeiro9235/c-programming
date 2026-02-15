#include <stdio.h>

int main() {
    int numero, qnt_divisores = 0;

    do {
        printf("Digite um número inteiro maior que 1: ");
        scanf("%d", &numero);
    } while(numero <= 1);

    for(int i = numero; i >= 1; i--) {
        if(numero % i == 0) 
            qnt_divisores++;
    }

    if(qnt_divisores == 2) 
        printf("%d é um número primo!\n", numero);
    else
        printf("%d não é um número primo!\n", numero);

    return 0;
}
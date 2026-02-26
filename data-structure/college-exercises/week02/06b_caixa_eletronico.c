#include <stdio.h>

int main() {
    int valor, qnt2 = 0, qnt5 = 0, qnt10 = 0, qnt20 = 0, qnt50 = 0, qnt100 = 0;

    do {
        printf("Digite o valor que você quer sacar: R$ ");
        scanf("%d", &valor);
    } while(valor < 0);

    if(valor != 1 && valor != 3) {
        if(valor % 5 == 3 || valor % 5 == 1) {
            qnt2 += (valor % 5 == 3) ? 4 : 3;
            valor -= (valor % 5 == 3) ? 8 : 6;
        }

        qnt100 += valor / 100;
        valor %= 100;

        qnt50 += valor / 50;
        valor %= 50;

        qnt20 += valor / 20;
        valor %= 20;

        qnt10 += valor / 10;
        valor %= 10;

        qnt5 += valor / 5;
        valor %= 5;

        qnt2 += valor / 2;
        valor %= 2;
        printf("\nVocê vai receber:\n");
        printf("\nNotas de R$ 100,00: %d\nNotas de R$ 50,00: %d\nNotas de R$ 20,00: %d\nNotas de R$ 10,00: %d\nNotas de R$ 5,00: %d\nNotas de R$ 2,00: %d\n", qnt100, qnt50, qnt20, qnt10, qnt5, qnt2);
    } else {
        printf("Não é possível sacar R$ %d,00", valor);
    }


    return 0;
}
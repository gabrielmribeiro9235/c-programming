#include <stdio.h>

int main() {
    int valor, ultimo_valor, qnt2 = 0, qnt5 = 0, qnt10 = 0, qnt20 = 0, qnt50 = 0, qnt100 = 0;

    do {
    printf("Digite o valor que quer sacar (inteiro e positivo): R$ ");
    scanf("%d", &valor);
    } while(valor < 0);

    if(valor == 3 || valor == 1) {
        printf("Impossível sacar R$ %d", valor);
    } else {
        while(valor > 0) {
            if(valor == 3 || valor == 1) {
                if(ultimo_valor > 100) {
                    qnt100--;
                    qnt50++;
                    qnt20 = qnt20 + 2;
                    qnt5++;
                    if(valor == 1) 
                        qnt2 = qnt2 + 3;
                    else
                        qnt2 = qnt2 + 4;
                    valor = 0;
                    continue;
                }
                if(ultimo_valor > 50) {
                    qnt50--;
                    qnt20 = qnt20 + 2;
                    qnt5++;
                    if(valor == 1) 
                        qnt2 = qnt2 + 3;
                    else
                        qnt2 = qnt2 + 4;
                    valor = 0;
                    continue;
                }
                if(ultimo_valor > 20) {
                    qnt20--;
                    qnt10++;
                    qnt5++;
                    if(valor == 1) 
                        qnt2 = qnt2 + 3;
                    else
                        qnt2 = qnt2 + 4;
                    valor = 0;
                    continue;
                }
                if(ultimo_valor > 10) {
                    qnt10--;
                    qnt5++;
                    if(valor == 1) 
                        qnt2 = qnt2 + 3;
                    else
                        qnt2 = qnt2 + 4;
                    valor = 0;
                    continue;
                }
            }
            if(valor >= 100) {
                ultimo_valor = valor;
                valor = valor - 100;
                qnt100++;
                continue;
            }
            if(valor >= 50) {
                ultimo_valor = valor;
                valor = valor - 50;
                qnt50++;
                continue;
            }
            if(valor >= 20) {
                ultimo_valor = valor;
                valor = valor - 20;
                qnt20++;
                continue;
            }
            if(valor >= 10) {
                ultimo_valor = valor;
                valor = valor - 10;
                qnt10++;
                continue;
            }
            if(valor >= 5) {
                ultimo_valor = valor;
                valor = valor - 5;
                qnt5++;
                continue;
            }
            if(valor >= 2) {
                ultimo_valor = valor;
                valor = valor - 2;
                qnt2++;
                continue;
            }
        }
        printf("\nVocê vai receber:\n\n");
        printf("Notas de R$ 100,00: %d\nNotas de R$ 50,00: %d\nNotas de R$ 20,00: %d\nNotas de R$ 10,00: %d\nNotas de R$ 5,00: %d\nNotas de R$ 2,00: %d", qnt100, qnt50, qnt20, qnt10, qnt5, qnt2);
    }
    
    return 0;
}
#include <stdio.h>

int main() {
    int quantidade, atual = 1, proximo = 1, auxiliar;
    
    do {
        printf("Insira a quantidade de números de Fibonacci que você quer ver: ");
        scanf("%d", &quantidade);
    } while(quantidade < 0);

    for(int i = 1; i <= quantidade; i++) {
        printf("%d ", atual);
        auxiliar = atual;
        atual = proximo;
        proximo += auxiliar;
    }

    return 0;
}
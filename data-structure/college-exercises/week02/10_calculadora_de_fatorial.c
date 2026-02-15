#include <stdio.h>

int main() {
    int numero, fatorial = 1;

    do {
        printf("Insira um número natural: ");
        scanf("%d", &numero);
    } while(numero < 0);
    
    int i = 1;
    while(i <= numero) {
        fatorial *= i;
        i++;
    }
    printf("Fatorial com while: %d\n", fatorial);
    fatorial = 1;
    
    for(int j = 1; j <= numero; j++) {
        fatorial *= j;
    }
    printf("Fatorial com for: %d\n", fatorial);    

    return 0;
}
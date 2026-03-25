#include <stdio.h>
#include <math.h>

int main() {
    int n; 
    printf("------------------------------------------------------\n");
    printf("Digite um número: ");
    scanf("%d", &n);

    int primos[n+1];

    float raiz = sqrt(n);

    for(int i = 0; i < n + 1; i++) {
        if(i == 1) {
            primos[i] = 0;
            continue;
        }
        primos[i] = i;
    }

    for(int i = 2; i <= raiz; i++){
        for(int j = 0; j < n+1; j++) {
            if(j % i == 0 && j != i) {
                primos[j] = 0;
            }
        }
    }

    printf("------------------------------------------------------\n");
    printf("Esses são todos os números primos de 2 até %d:\n", n);
    for(int i = 0; i < n + 1; i++) {
        if(primos[i] != 0)
            printf("%d   ", primos[i]);
    }
}
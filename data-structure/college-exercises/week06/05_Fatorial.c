#include <stdio.h>

int calcular_fatorial(int num);

int main() {
    printf("%d", calcular_fatorial(6));

    return 0;
}

int calcular_fatorial(int num) {
    int fatorial = 1;
    for(int i = num; i >= 1; i--) {
        fatorial *= i;
    }
    return fatorial;
}
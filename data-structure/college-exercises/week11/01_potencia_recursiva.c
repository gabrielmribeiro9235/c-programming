#include <stdio.h>

int potenciacao_recursiva(int base, int exp);

int main() {
    int resultado = potenciacao_recursiva(10, 5);
    printf("Resultado: %d\n", resultado);
    return 0;
}

int potenciacao_recursiva(int base, int exp) {
    if(exp == 0) 
        return 1;
    return base * potenciacao_recursiva(base, exp-1);
}
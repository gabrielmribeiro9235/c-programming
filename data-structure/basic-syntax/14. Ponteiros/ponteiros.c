#include <stdio.h>

void display(int var, int *p);
void update(int *p);

int main() {
    int variavel = 25;
    int *ponteiro;
    ponteiro = &variavel;

    display(variavel, ponteiro);
    
    update(&variavel);
    printf("\n\n");
    display(variavel, ponteiro);

    return 0;
}

void display(int var, int *p) {
    printf("Valor da variável            = %d\n", var);
    printf("Endereço da variável         = %p\n", &var);
    printf("Valor apontado pelo ponteiro = %d\n", *p);
    printf("Valor do ponteiro            = %p\n", p);
    printf("Endereço do ponteiro         = %p\n", &p);
}

void update(int *p) {
    *p += 1;
}
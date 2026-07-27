#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void insere_inicio(No **cabeca, int valor);
void teste_de_impressao(No **cabeca);

int main() {
    No *lista = NULL;
    int valor1 = 10, valor2 = 20, valor3 = 30;

    insere_inicio(&lista, valor1);
    insere_inicio(&lista, valor2);
    insere_inicio(&lista, valor3);

    teste_de_impressao(&lista);

    free(lista);
    lista = NULL;
    return 0;
}

void insere_inicio(No **cabeca, int valor) {
    if(*cabeca == NULL) {
        *cabeca = malloc(sizeof(No));
        if(*cabeca == NULL) return;
        (*cabeca)->valor = valor;
        (*cabeca)->proximo = NULL;
    } else {
        No *deslocamento = malloc(sizeof(No));
        deslocamento->valor = (*cabeca)->valor;
        deslocamento->proximo = (*cabeca)->proximo;
        (*cabeca)->valor = valor;
        (*cabeca)->proximo = deslocamento;
    }
    
}

void teste_de_impressao(No **cabeca) {
    if(*cabeca == NULL) return;

    if((*cabeca)->proximo == NULL) {
        printf("%d\t", (*cabeca)->valor);
        return;
    }

    printf("%d\t", (*cabeca)->valor);
    teste_de_impressao(&(*cabeca)->proximo);
}
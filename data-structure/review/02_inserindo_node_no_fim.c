#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void insere_fim(No **cabeca, int valor);
void teste_de_impressao(No **cabeca);

int main() {
    No *lista = NULL;
    int valor1 = 10, valor2 = 20, valor3 = 30;
    
    insere_fim(&lista, valor1);
    insere_fim(&lista, valor2);
    insere_fim(&lista, valor3);
    
    teste_de_impressao(&lista);
    
    free(lista);
    lista = NULL;
    
    return 0;
}

void insere_fim(No **cabeca, int valor) {
    if(*cabeca == NULL) {
        *cabeca = malloc(sizeof(No));
        if(*cabeca == NULL) return;
        (*cabeca)->valor = valor;
        (*cabeca)->proximo = NULL;
    } else {
        No *ultimo = malloc(sizeof(No));
        if(ultimo == NULL) return;
        No *cauda = malloc(sizeof(No));
        cauda = *cabeca;
        while (cauda->proximo != NULL) {
            cauda = cauda->proximo;
        }
        ultimo->valor = valor;
        ultimo->proximo = NULL;
        cauda->proximo = ultimo;
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
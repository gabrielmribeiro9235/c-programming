#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void libera_lista(No **cabeca);
void insere_fim(No **cabeca, int valor);

int main() {
    No *lista = NULL;
    
    insere_fim(&lista, 10);
    insere_fim(&lista, 20);
    insere_fim(&lista, 30);
    insere_fim(&lista, 40);
    
    libera_lista(&lista);
    
    return 0;
}

void libera_lista(No **cabeca) {
    No *atual = *cabeca;
    while(atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *cabeca = NULL;
}

void insere_fim(No **cabeca, int valor) {
    while (*cabeca != NULL) {
        cabeca = &(*cabeca)->proximo;
    }
    *cabeca = malloc(sizeof(No));
    if(*cabeca == NULL) return;
    (*cabeca)->valor = valor;
    (*cabeca)->proximo = NULL;
}

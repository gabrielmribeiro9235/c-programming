#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void imprime_lista(No *cabeca);

int main() {
    No *lista = NULL;
    No node3 = { 
        .valor = 20,
        .proximo = NULL
    };
    No node2 = { 
        .valor = 30,
        .proximo = &node3
    };

    lista = malloc(sizeof(No));
    lista->valor = 10;
    lista->proximo = &node2;

    imprime_lista(lista);

    free(lista);
    lista = NULL;

    return 0;
}

void imprime_lista(No *cabeca) {
    if(cabeca == NULL) return;

    while(cabeca->proximo != NULL) {
        printf("%d -> ", cabeca->valor);
        cabeca = cabeca->proximo;
    }
    printf("%d -> NULL\n", cabeca->valor);
}
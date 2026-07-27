#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void remove_valor(No **cabeca, int valor);
void imprime_lista(No *cabeca);

int main() {
    No node4 = {
        .valor = 40,
        .proximo = NULL
    };
    No node3 = { 
        .valor = 30,
        .proximo = &node4
    };
    No node2 = { 
        .valor = 20,
        .proximo = &node3
    };
    
    No *lista = malloc(sizeof(No));
    lista->valor = 10;
    lista->proximo = &node2;
    
    imprime_lista(lista);
    
    remove_valor(&lista, 50);
    
    imprime_lista(lista);

    free(lista);
    
    return 0;
}

void remove_valor(No **cabeca, int valor) {
    No *node_anterior = malloc(sizeof(No));
    No *node_posterior = malloc(sizeof(No));
    No *cauda = malloc (sizeof(No));
    int isHead = 1;
    
    if(node_anterior == NULL || node_posterior == NULL || cauda == NULL) return;

    cauda = *cabeca;

    while (cauda->valor != valor && cauda->proximo != NULL) {
        isHead = 0;
        node_anterior = cauda;
        cauda = cauda->proximo;
    }
    
    if(cauda->valor != valor) return;
    
    node_posterior = cauda->proximo;
    
    if(!isHead) {
        cauda = node_anterior;
        cauda->proximo = node_posterior;
    } else {
        *cabeca = (*cabeca)->proximo;
    }
}

void imprime_lista(No *cabeca) {
    if(cabeca == NULL) return;

    while(cabeca->proximo != NULL) {
        printf("%d -> ", cabeca->valor);
        cabeca = cabeca->proximo;
    }
    printf("%d -> NULL\n", cabeca->valor);
}
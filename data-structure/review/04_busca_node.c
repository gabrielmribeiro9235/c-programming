#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

No *busca(No **cabeca, int valor);

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
    
    No *node_buscado = busca(&lista, 40);
    if(node_buscado == NULL) {
        printf("NULL\n");
    } else if(node_buscado->proximo == NULL) {
        printf("Node buscado: %d\nValor do próximo nó: NULL\n", node_buscado->valor);
    } else {
        printf("Node buscado: %d\nValor do próximo nó: %d\n", node_buscado->valor, node_buscado->proximo->valor);
    }
    
    free(lista);
    lista = NULL;
    
    return 0;
}

No *busca(No **cabeca, int valor) {
    if(cabeca == NULL) return NULL;
    while ((*cabeca)->valor != valor && (*cabeca)->proximo != NULL) {
        *cabeca = (*cabeca)->proximo;
    }
    if((*cabeca)->valor == valor) {
        return *cabeca;
    } 
    return NULL;
}
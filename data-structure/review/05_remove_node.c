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
    
    remove_valor(&lista, 30);
    
    imprime_lista(lista);

    free(lista);
    
    return 0;
}

void remove_valor(No **cabeca, int valor) {
    if(cabeca == NULL) return;

    No *node_remover = *cabeca;
    No *anterior = NULL;

    while(node_remover != NULL) {
        if(node_remover->valor == valor) break;
        anterior = node_remover;
        node_remover = node_remover->proximo;
    }
    
    if(node_remover == NULL) return;

    if(anterior == NULL) {
        *cabeca = node_remover->proximo;
    } else {
        anterior->proximo = node_remover->proximo;
    }
    node_remover = NULL;
}

void imprime_lista(No *cabeca) {
    if(cabeca == NULL) return;

    while(cabeca->proximo != NULL) {
        printf("%d -> ", cabeca->valor);
        cabeca = cabeca->proximo;
    }
    printf("%d -> NULL\n", cabeca->valor);
}
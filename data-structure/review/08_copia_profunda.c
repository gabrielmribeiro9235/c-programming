#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

No *copia_lista(No *lista);
void insere_fim(No **cabeca, int valor);
void teste_de_impressao(No *cabeca);
void libera_lista(No **cabeca);

int main() {
    No *lista = NULL;
    
    insere_fim(&lista, 10);
    insere_fim(&lista, 20);
    insere_fim(&lista, 30);
    insere_fim(&lista, 40);
    
    No *nova_lista = copia_lista(lista);

    printf("Lista inicial:\t");
    teste_de_impressao(lista);
    printf("\nNova lista:\t");
    teste_de_impressao(nova_lista);

    libera_lista(&lista);
    
    return 0;
}

No *copia_lista(No *lista) {
    if(lista == NULL) return NULL;

    No *cabeca = malloc(sizeof(No));
    if(cabeca == NULL) return NULL;
    cabeca->valor = lista->valor;
    cabeca->proximo = NULL;
    
    No *copia_atual = cabeca;
    lista = lista->proximo;

    while(lista != NULL) {
        copia_atual->proximo = malloc(sizeof(No));
        copia_atual = copia_atual->proximo;
        copia_atual->valor = lista->valor;
        copia_atual->proximo = NULL;
        lista = lista->proximo;
    }

    return cabeca;
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

void teste_de_impressao(No *cabeca) {
    while(cabeca != NULL) {
        printf("%d\t", cabeca->valor);
        cabeca = cabeca->proximo;
    }
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
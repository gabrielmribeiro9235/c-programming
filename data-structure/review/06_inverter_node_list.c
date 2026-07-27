#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void inverte(No **cabeca);
void insere_fim(No **cabeca, int valor);
void teste_de_impressao(No **cabeca);
void libera_memoria(No **cabeca);

int main() {
    No *lista = NULL;
    
    insere_fim(&lista, 10);
    insere_fim(&lista, 20);
    insere_fim(&lista, 30);
    insere_fim(&lista, 40);
    
    teste_de_impressao(&lista);
    
    inverte(&lista);
    
    printf("\n");
    teste_de_impressao(&lista);
    
    libera_memoria(&lista);
    
    return 0;
}

void inverte(No **cabeca) {
    if(*cabeca == NULL || (*cabeca)->proximo == NULL) return;
    No *anterior = NULL;
    No *proximo = NULL;
    while(*cabeca != NULL) {
        if(anterior == NULL) {
            proximo = (*cabeca)->proximo;
            anterior = *cabeca;
            *cabeca = proximo;
            anterior->proximo = NULL;
        } else {
            proximo = (*cabeca)->proximo;
            (*cabeca)->proximo = anterior;
            anterior = *cabeca;
            *cabeca = proximo;
        }
    }
    *cabeca = anterior;
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

void teste_de_impressao(No **cabeca) {
    if(*cabeca == NULL) return;
    
    printf("%d\t", (*cabeca)->valor);
    teste_de_impressao(&(*cabeca)->proximo);
}

void libera_memoria(No **cabeca) {
    No *atual = *cabeca;
    while(atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *cabeca = NULL;
}
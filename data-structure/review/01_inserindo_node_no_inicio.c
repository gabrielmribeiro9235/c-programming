#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void insere_inicio(No **cabeca, int valor);
void teste_de_impressao(No **cabeca);
void libera_memoria(No **cabeca);

int main() {
    No *lista = NULL;
    int valor1 = 10, valor2 = 20, valor3 = 30;
    
    insere_inicio(&lista, valor1);
    insere_inicio(&lista, valor2);
    insere_inicio(&lista, valor3);
    
    teste_de_impressao(&lista);
    
    libera_memoria(&lista);
    
    return 0;
}

void insere_inicio(No **cabeca, int valor) {
    No *novo = malloc(sizeof(No));
    
    if(novo == NULL) return;
    
    novo->valor = valor;
    novo->proximo = *cabeca;
    *cabeca = novo;
}

void teste_de_impressao(No **cabeca) {
    if(*cabeca == NULL) return;
    
    printf("%d\t", (*cabeca)->valor);
    teste_de_impressao(&(*cabeca)->proximo);
}

void libera_memoria(No **cabeca) {
    No *atual = *cabeca;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *cabeca = NULL;    
}
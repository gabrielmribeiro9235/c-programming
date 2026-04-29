#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *nome;
    float preco;
} Produto;

Produto* criar_produto(int id, char *nome, float preco);
int alterar_nome(Produto *p, char *novoNome);
void liberar_memoria(Produto *p);

int main() {
    Produto *produto = criar_produto(1, "Nome", 10.0);
    if(!produto) {
        printf("Falha de alocação de memória!\n");
        return 1;
    }
    printf("----------------------------\n");
    printf("\tProduto inicial\n");
    printf("Id   : %d\n", produto->id);
    printf("Nome : %s\n", produto->nome);
    printf("Preco: R$ %.2f\n", produto->preco);
    int mudanca = alterar_nome(produto, "Novo nome");
    if(!mudanca) {
        liberar_memoria(produto); 
        return 0;
    }
    printf("----------------------------\n");
    printf("\tProduto mudado\n");
    printf("Id   : %d\n", produto->id);
    printf("Nome : %s\n", produto->nome);
    printf("Preco: R$ %.2f\n", produto->preco);
    liberar_memoria(produto);

    return 0;
}

Produto* criar_produto(int id, char *nome, float preco) {
    Produto *p = (Produto *)malloc(sizeof(Produto));
    if(!p) return NULL;
    p->id = id;
    p->preco = preco;

    p->nome = (char *)malloc(strlen(nome) + 1);
    if(!p->nome) {
        liberar_memoria(p);
        return NULL;
    }
    strcpy(p->nome, nome);
    return p;
}

int alterar_nome(Produto *p, char *novoNome) {
    char *novo = (char *)realloc(p->nome, strlen(novoNome) + 1);
    if(!novo) {
        printf("Falha de alocação de memória");
        return 0;
    }
    p->nome = novo;
    strcpy(p->nome, novoNome);
    return 1;
}

void liberar_memoria(Produto *p) {
    free(p->nome);
    free(p);
}

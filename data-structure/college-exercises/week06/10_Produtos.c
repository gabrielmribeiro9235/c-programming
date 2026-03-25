#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct {
    char nome[50];
    float preco;
    int qnt_em_estoque;
} Produto;

void ler_produtos(Produto produtos[], int tamanho);
void exibir_produtos(Produto produtos[], int tamanho);
void atuliza_estoque(Produto produtos[], int tamanho);
void reajuste_preco(Produto produtos[], int tamanho);

int main() {
    Produto lista_de_produtos[TAM];

    ler_produtos(lista_de_produtos, TAM);

    exibir_produtos(lista_de_produtos, TAM);
    
    atuliza_estoque(lista_de_produtos, TAM);
    
    exibir_produtos(lista_de_produtos, TAM);
    
    reajuste_preco(lista_de_produtos, TAM);

    exibir_produtos(lista_de_produtos, TAM);

    return 0;
}

void ler_produtos(Produto produtos[], int tamanho) {
    printf("--------------------------------------------------\n");
    printf("Insira os dados dos produtos\n");
    for(int i = 0; i < tamanho; i++) {
        printf("--------------------------------------------------\n");
        printf("Nome do produto %d: ", i+1);
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
        
        printf("Preço do produto %d: R$ ", i+1);
        scanf("%f", &produtos[i].preco);
        
        printf("Quantidade em estoque do produto %d: ", i+1);
        scanf("%d", &produtos[i].qnt_em_estoque);
        
        while(getchar() != '\n');
    }
}

void exibir_produtos(Produto produtos[], int tamanho) {
    printf("--------------------------------------------------\n");
    printf("Dados dos produtos\n");
    for(int i = 0; i < tamanho; i++) {
        printf("--------------------------------------------------\n");
        printf("Nome do produto %d: %s\n", i+1, produtos[i].nome);
        printf("Preço do produto %d: R$ %.2f\n", i+1, produtos[i].preco);
        printf("Quantidade em estoque do produto %d: %d\n", i+1, produtos[i].qnt_em_estoque);
    }
    printf("--------------------------------------------------\n");
}

void atuliza_estoque(Produto produtos[], int tamanho) {
    int flag_atualizacao;

    printf("Atualização do estoque\n");
    for(int i = 0; i < tamanho; i++) {
        printf("--------------------------------------------------\n");
        printf("Quer atualizar o estoque do produto %d?\n", i+1);
        printf("1 para sim\n");
        printf("2 para não\n");
        printf("Sua escolha: ");
        scanf("%d", &flag_atualizacao);
        while(getchar() != '\n');
        if(flag_atualizacao == 1) {
            printf("--------------------------------------\n");
            printf("Novo estoque do produto %d: ", i+1);
            scanf("%d", &produtos[i].qnt_em_estoque);
        }
    }
}

void reajuste_preco(Produto produtos[], int tamanho) {
    float porcentagem, fator_de_reajuste;

    printf("Digite a porcentagem de reajuste: ");
    scanf("%f", &porcentagem);

    fator_de_reajuste = 1 + (porcentagem / 100);

    for(int i = 0; i < tamanho; i++) {
        produtos[i].preco *= fator_de_reajuste;
    }
}
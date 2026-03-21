#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct {
    char nome[50];
    float preco;
    int qnt_em_estoque;
} Produto;

int main() {
    Produto produtos[TAM];
    float capital_financeiro[TAM], soma = 0.0, media;

    printf("---------------------------------------------------------------\n");
    for(int i = 0; i < TAM; i++) {
        printf("Digite o nome do produto %d: ", i+1);
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome,"\n")] = '\0';

        printf("Digite o preço do produto %d: R$ ", i+1);
        scanf("%f", &produtos[i].preco);

        printf("Digite a quantidade em estoque do produto %d: ", i+1);
        scanf("%d", &produtos[i].qnt_em_estoque);

        capital_financeiro[i] = produtos[i].qnt_em_estoque * produtos[i].preco;
        printf("---------------------------------------------------------------\n");
        while(getchar() != '\n');
    }

    printf("Capital financeiro em estoque para cada produto:\n");
    for(int i = 0; i < TAM; i++) {
        printf("Produto %d: R$ %.2f\n", i+1, capital_financeiro[i]);
    }

    for(int i = 0; i < TAM; i++) {
        soma += produtos[i].preco;
    }
    media = soma / TAM;

    printf("\nMédia de preços dos produtos: R$ %.2f\n", media);

    printf("\nProdutos com preço acima da média:\n");
    for(int i = 0; i < TAM; i++) {
        if(produtos[i].preco > media){
            printf("Produto %d: R$ %.2f\n", i+1, produtos[i].preco);
        }
    }

    return 0;
}
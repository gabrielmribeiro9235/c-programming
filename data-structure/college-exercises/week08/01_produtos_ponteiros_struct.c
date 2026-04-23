#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

void ler_produto(Produto *p);
void atualizar_preco(Produto *p, float porcentagem);
int obter_mais_caro(Produto *p1, Produto *p2);

int main() {
    Produto produto1, produto2;
    ler_produto(&produto1);
    ler_produto(&produto2);

    int mais_caro = obter_mais_caro(&produto1, &produto2);
    printf("-----------------------------------\n");
    if(mais_caro == 0) 
        printf("Os dois produtos têm o mesmo preço!\n");
    if(mais_caro == 1) 
        printf("O produto 1 é o mais caro!\n");
    if(mais_caro == 2) 
        printf("O produto 2 é o mais caro!\n");

    printf("-----------------------------------\n");
    printf("Dados do produto 1\n");
    printf("ID: %d\nNome: %s\nPreço: R$ %.2f\n", produto1.id, produto1.nome, produto1.preco);
    printf("-----------------------------------\n");
    printf("Dados do produto 2\n");
    printf("ID: %d\nNome: %s\nPreço: R$ %.2f\n", produto2.id, produto2.nome, produto2.preco);

    return 0;
}

void ler_produto(Produto *p) {
    printf("-----------------------------------\n");
    printf("Cadestre os dados do produto\n");
    printf("ID: ");
    scanf("%d", &p->id);
    while(getchar() != '\n');
    printf("Nome: ");
    fgets(p->nome, sizeof(p->nome), stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';
    printf("Preço: R$ ");
    scanf("%f", &p->preco);
    while(getchar() != '\n');
}

void atualizar_preco(Produto *p, float porcentagem) {
    p->preco *= (1 + (porcentagem / 100));
    printf("Preço atualizado em %.1f%%\n", porcentagem);
}

int obter_mais_caro(Produto *p1, Produto *p2) {
    if(p1->preco == p2->preco)
        return 0;
    if(p1-> preco > p2->preco)
        return 1;
    return 2;
}
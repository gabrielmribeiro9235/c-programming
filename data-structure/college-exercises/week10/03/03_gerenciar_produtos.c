#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto; 

void salvarProduto(Produto p); 
void listarProdutos();
float calcularMedia(char *path);
Produto *buscarPorId(char *path, int id);

int main() {    
    Produto p1 = {1, "Teclado Mecânico", 250.0};
    Produto p2 = {2, "Mouse Gamer", 100.0};
    salvarProduto(p1);
    salvarProduto(p2);
    listarProdutos();
    float media = calcularMedia("produtos.txt");
    if(media == -1.0) {
        printf("Não foi possível abrir o arquivo!");
    }
    printf("Preço médio dos produtos: R$ %.2f\n", media);
    Produto *produtoBuscado = buscarPorId("produtos.txt", 1);
    if(produtoBuscado == NULL) {
        printf("Produto não encontrado");
        return 0;
    }
    printf("------------------------------------\n");
    printf("\tProduto buscado:\n");
    printf("ID   : %d\n", produtoBuscado->id);
    printf("Nome : %s\n", produtoBuscado->nome);
    printf("Preço: R$ %.2f\n", produtoBuscado->preco);
    free(produtoBuscado);
    return 0;
}

void salvarProduto(Produto p) {
    FILE *arq = fopen("produtos.txt", "a");
    if (arq == NULL)
        return;
    fprintf(arq, "%d;%s;%.2f\n", p.id, p.nome, p.preco);
    fclose(arq);
}


void listarProdutos() {
    FILE *arq = fopen("produtos.txt", "r");
    if (arq == NULL)
       return;
    int id;
    char nome[50];
    float preco;
    while(fscanf(arq, "%d;%[^;];%f\n", &id, nome, &preco) == 3) {
        printf("Id: %d\n", id);
        printf("Nome: %s\n", nome);
        printf("Preço: R$ %.2f\n", preco);
        printf("------------------------------------\n");
    }
    fclose(arq);
}

float calcularMedia(char *path) {
    FILE *file = fopen(path, "r");
    if(file == NULL){
        return -1.0;
    }
    float soma = 0.0;
    int count = 0;
    Produto p;
    while(fscanf(file, "%d;%[^;];%f", &p.id, p.nome, &p.preco) == 3) {
        soma += p.preco;
        count++;
    }
    fclose(file);
    if(count == 0) {
        return -1.0;
    }
    return soma/count;
}

Produto *buscarPorId(char *path, int id) {
    FILE *file = fopen(path, "r");
    if(file == NULL){
        return NULL;
    }
    Produto *p = malloc(sizeof(Produto));
    while(fscanf(file, "%d;%[^;];%f", &p->id, p->nome, &p->preco) == 3) {
        if(p->id == id) {
            fclose(file);
            return p;
        }
    }
    free(p);
    fclose(file);
    return NULL;
}

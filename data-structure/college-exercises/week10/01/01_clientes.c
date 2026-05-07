#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

typedef struct {
    char nome[50];
    char email[50];
} Cliente;

void ler_e_gravar_dados(int n, char *path);
void gravar_dados(Cliente *clientes, int n, char *path);
void mostrar_arquivo(char *path);

int main() {
    char *path = "clientes.txt";
    ler_e_gravar_dados(N, path);
    mostrar_arquivo(path);
}

void ler_e_gravar_dados(int n, char *path) {
    Cliente *clientes = malloc(sizeof(Cliente) * n);
    if(clientes == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        printf("-----------------------\n");
        printf("Cliente %d\n", i+1);
        printf("Nome : ");
        fgets((clientes + i)->nome, sizeof((clientes + i)->nome), stdin);
        (clientes + i)->nome[strcspn((clientes + i)->nome, "\n")] = '\0';
        printf("Email: ");
        fgets((clientes + i)->email, sizeof((clientes + i)->email), stdin);
        (clientes + i)->email[strcspn((clientes + i)->email, "\n")] = '\0';
    }
    printf("-----------------------\n");
    gravar_dados(clientes, n, path);
}

void gravar_dados(Cliente *clientes, int n, char *path) {
    FILE *file = fopen(path, "w");
    for(int i = 0; i < n; i++) {
        fprintf(file, "Nome: %s  |  Email: %s\n", (clientes + i)->nome, (clientes + i)->email);
    }
    fclose(file);
}

void mostrar_arquivo(char *path) {
    FILE *file = fopen(path, "r");
    if(file == NULL) {
        printf("Arquivo não encontrado!\n");
        exit(1);
    }
    char linha[100];
    while(fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }
    fclose(file);
}
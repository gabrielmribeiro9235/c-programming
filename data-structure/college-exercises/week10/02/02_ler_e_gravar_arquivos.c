#include <stdio.h>

void *ler_arquivo(char *path);
void gravar_arquivo(FILE *origem, char *path);

int main() {
    FILE *origem = ler_arquivo("origem.txt");
    if(origem == NULL) {
        printf("Erro ao abrir o arquivo");
    }
    gravar_arquivo(origem, "destino.txt");
    fclose(origem);
    return 0;
}

void *ler_arquivo(char *path) {
    return fopen(path, "r");
}

void gravar_arquivo(FILE *origem, char *path) {
    FILE *destino = fopen(path, "w");
    char linha[100];
    while(fgets(linha, sizeof(linha), origem) != NULL) {
        fprintf(destino, linha);
    }
    fclose(destino);
}

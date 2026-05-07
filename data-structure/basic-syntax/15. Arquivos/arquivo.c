#include <stdio.h>
#include <stdlib.h>

int main() {
    // Escrita
    FILE *file1 = fopen("teste.txt", "w");
    if(file1 == NULL) {
        printf("Erro!");
        exit(0);
    }
    fprintf(file1, "Teste de gravacao 1\n");
    fputs("Teste de gravacao 2\n", file1);
    fclose(file1);
    // Leitura
    FILE *file2 = fopen("teste.txt", "r");
    if(file2 == NULL) {
        printf("Erro!");
        exit(1);
    }
    char *linha = malloc(sizeof(char) * 100);
    if(file2 == NULL) {
        printf("Erro!");
        exit(1);
    }
    while(fgets(linha, sizeof(linha), file2) != NULL) {
        printf("%s", linha);    
    }
    fclose(file2);
    // Adição
    FILE *file3 = fopen("teste.txt", "a");
    if(file3 == NULL) {
        printf("Erro!");
        exit(0);
    }
    fprintf(file3, "Adicao 1\n");
    fputs("Adicao 2\n", file3);
    fputc('a', file3);
    fclose(file3);
    return 0;
}
#include <stdio.h>

int main() {
    char string[100], invertida[100];
    int contador_de_iguais = 0;

    printf("Digite uma palavra (apenas uma): ");
    scanf("%100s", string);

    int tamanho = 0;
    while(string[tamanho] != '\0') {
        tamanho++;
    }

    for(int i = 0; i < tamanho; i++) {
        invertida[i] = string[tamanho - (i+1)];
    }
    
    for(int i = 0; i < tamanho; i++) {
        if(invertida[i] == string[i]) {
            contador_de_iguais++;
        }
    }

    if(contador_de_iguais == tamanho) {
        printf("\"%s\" é palíndromo!\n", string);
    } else {
        printf("\"%s\" não é palíndromo!\n", string);
    }

    return 0;
}
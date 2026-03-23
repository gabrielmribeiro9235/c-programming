#include <stdio.h>
#include <string.h>
#define TAM 50

void lerString(char str[], int tamanho);
void substituirChar(char str[], char antigo, char novo);

int main() {
    char str[TAM];
    lerString(str, TAM);

    substituirChar(str, 'a', 'o');

    printf("%s", str);

    return 0;
}

void lerString(char str[], int tamanho) {
    printf("Digite algo: ");
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void substituirChar(char str[], char antigo, char novo) {
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] == antigo)
            str[i] = novo;
        i++;
    }
}
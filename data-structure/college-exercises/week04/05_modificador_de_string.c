#include <stdio.h>

int main() {
    char string[100], caractere;

    printf("Digite algo: ");
    scanf("%100[^\n]", string);

    while(getchar() != '\n');

    printf("Digite o caractere que você quer substituir: ");
    scanf("%c", &caractere);

    int i = 0;
    while(string[i] != '\0') {
        if(string[i] == caractere) {
            string[i] = '*';
        }
        i++;
    }

    printf("\nString depois da substituição: \"%s\"", string);

    return 0;
}
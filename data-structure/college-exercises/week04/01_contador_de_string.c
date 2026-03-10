#include <stdio.h>

int main() {
    char string[100];

    printf("Digite algo: ");
    scanf("%100[^\n]", string);

    int i = 0;
    while(string[i] != '\0') {
        i++;
    }

    printf("\"%s\" tem %d caracteres.\n", string, i);

    return 0;
}
#include <stdio.h>

int main() {
    char vogais[] = "aeiouAEIOU", string[100];
    int contador_vogais = 0;

    printf("Digite algo: ");
    scanf("%100[^\n]", string);

    int i = 0;
    while(string[i] != '\0') {
        for(int j = 0; j < 10; j++) {
            if(string[i] == vogais[j]) {
                contador_vogais++;
            }
        }
        i++;
    }

    printf("\"%s\" tem %d vogais.\n", string, contador_vogais);

    return 0;
}
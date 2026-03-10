#include <stdio.h>

int main() {
    char username[100], letras[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int criterio1 = 0, criterio2 = 0, criterio3 = 1;

    printf("Digite seu nome de usuário: ");
    scanf("%100[^\n]", username);

    int tamanho = 0;
    while(username[tamanho] != '\0') {
        tamanho++;
    }

    for(int i = 0; i < 52; i++) {
        if(username[0] == letras[i]) {
            criterio1 = 1;
        }
    }

    if(tamanho > 5 && tamanho < 15) {
        criterio2 = 1;
    }

    for(int i = 0; i < tamanho; i++) {
        if(username[i] == ' ') {
            criterio3 = 0;
        }
    }

    if(criterio1 && criterio2 && criterio3) {
        printf("\"%s\" é um nome de usuário válido.\n", username);
    } else {
        printf("\"%s\" não é um nome de usuário válido.\n", username);
    }

    return 0;
}
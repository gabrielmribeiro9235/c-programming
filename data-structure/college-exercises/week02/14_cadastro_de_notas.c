#include <stdio.h>

int main() {
    float nota, media, soma_notas = 0, maior;

    for(int i = 1; i <= 5; i++) {
        media = 0;
        soma_notas = 0;
        nota = 0;
        int j = 1;
        while (j <= 2) {
            printf("Digite a nota %d do Aluno %d: ", j, i);
            scanf("%f", &nota);
            if(nota >= 0 && nota <= 10) {
                soma_notas += nota;
                j++;
            }
        }
        media = soma_notas / 2;
        if(i == 1) {
            maior = media;
        } else {
            if(media > maior)
                maior = media;
        }
        printf("Situação do Aluno %d: ", i);
        if(media >= 6)
            printf("Aprovado\n\n");
        else if(media >= 4)
            printf("IFA\n\n");
        else
            printf("Reprovado\n\n");
    }
    printf("Maior média: %.2f", maior);

    return 0;
}
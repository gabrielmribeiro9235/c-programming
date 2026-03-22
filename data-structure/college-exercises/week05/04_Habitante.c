#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct {
    float salario;
    char sexo;
    int idade, num_de_filhos;
} Habitante;

int main() {
    Habitante habitantes[TAM];
    float menor_salario, maior_salario, media_salarios, soma_salarios = 0.0, media_filhos, pct_mulheres_mais2000;
    int qnt_mulheres_mais2000 = 0, total_mulheres = 0,  soma_filhos = 0;


    printf("--------------------------------------------------\n");
    for(int i = 0; i < TAM; i++) {
        printf("Habitante %d\n\n", i+1);
        
        printf("Salário: ");
        scanf("%f", &habitantes[i].salario);
        if(i == 0) {
            menor_salario = habitantes[i].salario;
            maior_salario = habitantes[i].salario;
        } else {
            if(habitantes[i].salario > maior_salario) {
                maior_salario = habitantes[i].salario;
            }
            if(habitantes[i].salario < menor_salario) {
                menor_salario = habitantes[i].salario;
            }
        }
        soma_salarios += habitantes[i].salario;

        while(getchar() != '\n');
        printf("Sexo [M/F]: ");
        scanf("%c", &habitantes[i].sexo);
        if(habitantes[i].sexo == 'f' || habitantes[i].sexo == 'F') {
            total_mulheres++;
            if(habitantes[i].salario > 2000) {
                qnt_mulheres_mais2000++;
            }
        }

        printf("Idade: ");
        scanf("%d", &habitantes[i].idade);

        printf("Número de filhos: ");
        scanf("%d", &habitantes[i].num_de_filhos);
        soma_filhos += habitantes[i].num_de_filhos;

        printf("--------------------------------------------------\n");
        while(getchar() != '\n');
    }

    media_salarios = soma_salarios / TAM;
    media_filhos = (float) soma_filhos / TAM;
    pct_mulheres_mais2000 = ((float) qnt_mulheres_mais2000 / total_mulheres) * 100;

    printf("\nMédia salarial: R$ %.2f\n", media_salarios);
    printf("Número médio de filhos por habitante: %.1f\n", media_filhos);
    printf("Menor salário: R$ %.2f\n", menor_salario);
    printf("Maior salário: R$ %.2f\n", maior_salario);
    printf("Percentual de mulheres que ganham mais de R$ 2000.00: %.2f %%\n", pct_mulheres_mais2000);

    return 0;
}
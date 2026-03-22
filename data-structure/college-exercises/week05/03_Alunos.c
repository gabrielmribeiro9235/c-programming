#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct {
    char prontuario[20];
    char nome[50];
    float notas[3]; 
} Aluno;

int main() {
    Aluno alunos[TAM];

    printf("---------------------------------------------------\n");
    for(int i = 0; i < TAM; i++) {
        printf("\t\t\tAluno %d\n", i+1);
        
        printf("Prontuário: ");
        fgets(alunos[i].prontuario, sizeof(alunos[i].prontuario), stdin);
        alunos[i].prontuario[strcspn(alunos[i].prontuario, "\n")] = '\0';

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        for(int j = 0; j < 3; j++) {
            do {
                printf("Nota %d: ", j+1);
                scanf("%f", &alunos[i].notas[j]);
            } while(alunos[i].notas[j] < 0 || alunos[i].notas[j] > 10);
        }
        while(getchar() != '\n');
        printf("---------------------------------------------------\n");
    }

    for(int i = 0; i < TAM; i++) {
        float soma = 0, media = 0;
        
        for(int j = 0; j < 3; j++) {
            soma += alunos[i].notas[j];
        }
        media = soma / 3;
        
        if(media >= 6) {
            printf("Aluno %d: Aprovado\n", i+1);
            continue;
        }
        if(media >= 4) {
            printf("Aluno %d: IFA\n", i+1);
            continue;
        }
        printf("Aluno %d: Reprovado\n", i+1);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char prontuario[10];
    char nome[100];
    float ira;
} Aluno;

typedef struct {
    Aluno *dados;
    int quantidade;
} Turma;

void inicializarTurma(Turma *turma);
void carregarDados(Turma *turma);
void cadastrarAluno(Turma *turma, Aluno *aluno);
void listarAlunos(Turma *turma);
void ordenarPorProntuario(Turma *turma);

void inicializarTurma(Turma *turma) {
    turma->dados = NULL;
    turma->quantidade = 0;

    printf("Turma criada e pronta para receber alunos!\n");
}

void carregarDados(Turma *turma) {
    FILE *arq = fopen("dados.bin", "rb");

    if(arq == NULL)
        return;
    
    fread(&turma->quantidade, sizeof(int), 1, arq);

    if(turma->quantidade > 0) {
        turma->dados = (Aluno *)malloc(sizeof(Aluno) * turma->quantidade);

        if(turma->dados == NULL)
            exit(1);

        fread(turma->dados, sizeof(Aluno), turma->quantidade, arq);
    }

    fclose(arq);
}

void cadastrarAluno(Turma *turma, Aluno *aluno) {
    Aluno *temp = (Aluno *)realloc(turma->dados, (turma->quantidade + 1) * sizeof(Aluno));

    if(temp == NULL) {
        printf("Falha ao cadastrar o novo aluno!\n");
        return;
    }

    turma->dados = temp;
    turma->dados[turma->quantidade] = *aluno;
    turma->quantidade++;
}

void listarAlunos(Turma *turma) {
    for(int i = 0; i < turma->quantidade; i++) {
        printf("--------------------------------\n");
        printf("Aluno %d\n", i+1);
        printf("Prontuário: %s\n", turma->dados[i].prontuario);
        printf("Nome      : %s\n", turma->dados[i].nome);
        printf("IRA       : %.2f\n", turma->dados[i].ira);
    }
}

void ordenarPorProntuario(Turma *turma) {
    for(int i = 0; i < turma->quantidade - 1; i++) {
        int swapped = 0;

        for(int j = 0; j < turma->quantidade - 1 - i; j++) {
            if(strcmp(turma->dados[j].prontuario, turma->dados[j+1].prontuario) > 0) {
                Aluno temp = turma->dados[j];
                turma->dados[j] = turma->dados[j+1];
                turma->dados[j+1] = temp;

                swapped = 1;
            }
        }
        
        if(swapped == 0)
            break;
    }
}
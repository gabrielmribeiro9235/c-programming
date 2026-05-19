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
    turma->dados[turma->quantidade-1] = *aluno;
    turma->quantidade++;
}
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
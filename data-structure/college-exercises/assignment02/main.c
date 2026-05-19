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

void inicializarTurma(Turma *turma) {
    turma->dados = NULL;
    turma->quantidade = 0;

    printf("Turma criada e pronta para receber alunos!\n");
}
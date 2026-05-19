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

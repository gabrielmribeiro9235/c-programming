#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO 0
#define OK 1

typedef struct {
    char prontuario[10];
    char nome[100];
    float ira;
} Aluno;

typedef struct {
    Aluno *dados;
    int quantidade;
} Turma;

int menu();
void inicializarTurma(Turma *turma);
void carregarDados(Turma *turma);
void cadastrarAluno(Turma *turma, Aluno *aluno);
void listarAlunos(Turma *turma);
void ordenarPorProntuario(Turma *turma);
void ordenarPorIRA(Turma *turma);
Aluno* buscarAluno(Turma *turma, char prontuario[]);
int removerAluno(Turma *turma, char prontuario[], Aluno *aluno);
void salvar(Turma *turma);
void liberarMemoria(Turma *turma);

int main() {
    Turma turma;
    
    inicializarTurma(&turma);
    carregarDados(&turma);
    
    int escolha;
    
    do {
        escolha = menu();
        
        switch (escolha) {
            case 1: {
                Aluno novo_aluno;

                printf("------------------------------------------------\n");
                printf("Cadastrar novo aluno:\n");

                printf("Prontuário: ");
                fgets(novo_aluno.prontuario, sizeof(novo_aluno.prontuario), stdin);
                novo_aluno.prontuario[strcspn(novo_aluno.prontuario, "\n")] = '\0';

                printf("Nome: ");
                fgets(novo_aluno.nome, sizeof(novo_aluno.nome), stdin);
                novo_aluno.nome[strcspn(novo_aluno.nome, "\n")] = '\0';

                printf("IRA: ");
                scanf("%f", &novo_aluno.ira);

                while(getchar() != '\n');

                printf("------------------------------------------------\n");
                cadastrarAluno(&turma, &novo_aluno);

                break;
            } case 2:
                listarAlunos(&turma);
                break;
            case 3: {
                char prontuario[10];

                printf("------------------------------------------------\n");
                printf("Insira o prontuário do aluno que quer buscar:\n");
                fgets(prontuario, sizeof(prontuario), stdin);
                prontuario[strcspn(prontuario, "\n")] = '\0';

                Aluno *aluno_buscado = buscarAluno(&turma, prontuario);

                printf("------------------------------------------------\n");
                
                if(aluno_buscado == NULL) {
                    printf("Aluno não encontrado!\n");
                    break;
                }
                
                printf("Aluno encontrado:\n");
                printf("Prontuário: %s\n", aluno_buscado->prontuario);
                printf("Nome      : %s\n", aluno_buscado->nome);
                printf("IRA       : %.2f\n", aluno_buscado->ira);
                
                break;
            } case 4:
                ordenarPorIRA(&turma);

                printf("------------------------------------------------\n");
                printf("Turma ordenada por IRA!\n");

                break;
            case 5:
                ordenarPorProntuario(&turma);

                printf("------------------------------------------------\n");
                printf("Turma ordenada por prontuário!\n");

                break;
            case 6: {
                char prontuario[10];

                printf("------------------------------------------------\n");
                printf("Insira o prontuário do aluno que quer remover:\n");
                fgets(prontuario, sizeof(prontuario), stdin);
                prontuario[strcspn(prontuario, "\n")] = '\0';
                
                Aluno aluno_removido;
                
                int remocao = removerAluno(&turma, prontuario, &aluno_removido);
                
                printf("------------------------------------------------\n");

                if(remocao == ERRO) {
                    printf("Aluno não encontrado!\n");
                    break;
                }

                printf("Aluno removido:\n");
                printf("Prontuário: %s\n", aluno_removido.prontuario);
                printf("Nome      : %s\n", aluno_removido.nome);
                printf("IRA       : %.2f\n", aluno_removido.ira);
                
                break;
            } case 7:
                printf("------------------------------------------------\n");
                salvar(&turma);

                break;
            case 8:
                break;
            default:
                printf("Escolha inválida\n");
                break;
        }
    } while (escolha != 8);
    
    printf("------------------------------------------------\n");
    salvar(&turma);
    liberarMemoria(&turma);
    
    printf("\nFim do programa\n");
    
    return 0;
}

int menu() {
    int escolha;

    printf("------------------------------------------------\n");
    printf("1. Cadastrar aluno\n");
    printf("2. Listar alunos\n");
    printf("3. Buscar aluno\n");
    printf("4. Ordenar por IRA\n");
    printf("5. Ordenar por prontuário\n");
    printf("6. Remover aluno\n");
    printf("7. Salvar\n");
    printf("8. Sair\n");
    printf("------------------------------------------------\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha);
    
    while(getchar() != '\n');

    return escolha;
}

void inicializarTurma(Turma *turma) {
    turma->dados = NULL;
    turma->quantidade = 0;
    
    printf("------------------------------------------------\n");
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

    printf("Novo aluno cadastrado.\n");
}

void listarAlunos(Turma *turma) {
    for(int i = 0; i < turma->quantidade; i++) {
        printf("------------------------------------------------\n");
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

void ordenarPorIRA(Turma *turma) {
    for(int i = 0; i < turma->quantidade - 1; i++) {
        int swapped = 0;

        for(int j = 0; j < turma->quantidade - 1 - i; j++) {
            if(turma->dados[j].ira > turma->dados[j+1].ira) {
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

Aluno* buscarAluno(Turma *turma, char prontuario[]) {
    // Como foi implementado um bubble sort, caso o array já esteja ordenado,
    // a lógica do swapped fará com que só haja uma iteração, evitando perda de tempo ordenando um array já ordenado
    ordenarPorProntuario(turma);

    int inicio = 0, fim = turma->quantidade - 1;

    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if(strcmp(turma->dados[meio].prontuario, prontuario) == 0) {
            return &turma->dados[meio];
        }
        
        if(strcmp(turma->dados[meio].prontuario, prontuario) > 0) {
            fim = meio - 1;
            continue;
        }
        
        inicio = meio + 1;
    } 
    return NULL;
}

int removerAluno(Turma *turma, char prontuario[], Aluno *aluno) {
    int idx_procurado = -1;

    for(int i = 0; i < turma->quantidade; i++) {
        if(strcmp(turma->dados[i].prontuario, prontuario) == 0) {
            idx_procurado = i;
            break;
        }
    }
    
    if(idx_procurado == -1)
        return ERRO;

    *aluno = turma->dados[idx_procurado];
    
    for(int i = idx_procurado; i < turma->quantidade - 1; i++)
        turma->dados[i] = turma->dados[i+1];
    
    turma->quantidade--;
    
    Aluno *temp = (Aluno *)realloc(turma->dados, sizeof(Aluno) * turma->quantidade);
    
    if(temp != NULL || turma->quantidade == 0)
        turma->dados = temp;
    
    return OK;
}

void salvar(Turma *turma) {
    FILE *arq = fopen("dados.bin", "wb");

    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    fwrite(&turma->quantidade, sizeof(int), 1, arq);
    fwrite(turma->dados, sizeof(Aluno), turma->quantidade, arq);
    
    fclose(arq);
    printf("Turma salva com sucesso!\n");
}

void liberarMemoria(Turma *turma) {
    free(turma->dados);
    turma->dados = NULL;
    turma->quantidade = 0;
}
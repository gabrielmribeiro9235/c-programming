#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char prontuario[20], nome[50];
    float notas[3];
} Aluno;

Aluno *ler_alunos(int n);
int gravar_alunos(int n, Aluno *lista_alunos, char *path);
Aluno *ler_arquivo(int n, char *path);
float *calcular_medias(Aluno *a, int n);
void mostrar_medias(float *medias, int n);
void mostrar_alunos(Aluno *a, int n);

int main() {
    int n;
    printf("Quantos alunos quer cadastrar?\n");
    scanf("%d", &n);
    while(getchar() != '\n');
    Aluno *alunos = ler_alunos(n);
    if(alunos == NULL) {
        printf("Erro ao cadastrar os alunos.\n");
        return 0;
    }
    int gravacao = gravar_alunos(n, alunos, "dados.bin");
    if(gravacao != n) {
        printf("Erro ao gravar arquivo\n");
        return 0;
    }
    free(alunos);
    Aluno *alunos_lidos = ler_arquivo(n, "dados.bin");
    if(alunos_lidos == NULL) {
        printf("Erro ao ler o arquivo\n");
        return 0;
    }
    float *medias = calcular_medias(alunos_lidos, n);
    if(medias == NULL) {
        printf("Erro ao calcular as médias.\n");
        return 0;
    }
    mostrar_medias(medias, n);
    mostrar_alunos(alunos_lidos, n);
    free(alunos_lidos);
    return 0;
}

Aluno *ler_alunos(int n) {
    Aluno *alunos = (Aluno*)malloc(sizeof(Aluno)*n);
    if(alunos == NULL) 
        return alunos;
    for(int i = 0; i < n; i++) {
        printf("-------------------------\n");
        printf("Aluno %d\n", i+1);
        printf("Prontuário: ");
        fgets(alunos[i].prontuario, sizeof(alunos[i].prontuario), stdin);
        alunos[i].prontuario[strcspn(alunos[i].prontuario, "\n")] = '\0';
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        for(int j = 0; j < 3; j++) {
            printf("Nota %d: ", j+1);
            scanf("%f", &alunos[i].notas[j]);
        }
        while(getchar() != '\n');
    }
    return alunos;
}

int gravar_alunos(int n, Aluno *lista_alunos, char *path) {
    FILE *arq = fopen(path, "wb");
    if(arq == NULL) 
        return -1;
    int retorno = fwrite(lista_alunos, sizeof(Aluno), n, arq);
    fclose(arq);
    return retorno;
}

Aluno *ler_arquivo(int n, char *path) {
    FILE *arq = fopen(path, "rb");
    if(arq == NULL)
        return NULL;
    Aluno *alunos = (Aluno*)malloc(sizeof(Aluno) * n);
    int lidos = fread(alunos, sizeof(Aluno), n, arq);
    if(lidos != n)
    return NULL;
    fclose(arq);
    return alunos;
}

float *calcular_medias(Aluno *a, int n) {
    float *m = (float*)malloc(3 * sizeof(float));
    if(m == NULL)
        return m;
    for(int i = 0; i < n; i++) {
        float soma = 0.0;
        for(int j = 0; j < 3; j++)
            soma += a[i].notas[j];
        m[i] = soma / 3;
    }
    return m;
}

void mostrar_medias(float *medias, int n) {
    for(int i = 0; i < n; i++) {
        printf("-------------------------\n");
        printf("Média do aluno %d: %.2f\n", i+1, medias[i]);
    }
}

void mostrar_alunos(Aluno *a, int n) {
    for(int i = 0; i < n; i++) {
        printf("-------------------------\n");
        printf("Aluno %d\n", i+1);
        printf("Prontuário: %s\n", a[i].prontuario);
        printf("Nome: %s\n", a[i].nome);
        for(int j = 0; j < 3; j++) 
            printf("Nota %d: %.2f\n", j+1, a[i].notas[j]);
    }
}
#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct {
    char matricula[10], nome[50];
    float salario;
} Funcionario;

void ler_dados(Funcionario funcionarios[], int tamanho);
void exibir_dados(Funcionario funcionarios[], int tamanho);
void buscar_funcionarios_pelo_nome(Funcionario funcionarios[], int tamanho, char nome[50]);
void reajustar_salario(Funcionario funcionarios[], int tamanho, char matricula_funcional[10], float reajuste);
float calcular_media(Funcionario funcionarios[], int tamanho);
Funcionario buscar_maior_salario(Funcionario funcionarios[], int tamanho);

int main() {
    Funcionario lista_de_funcionarios[TAM], funcionario_com_maior_salario;
    char nome[50], matricula_funcional[10];
    float porcentagem, media;

    ler_dados(lista_de_funcionarios, TAM);

    exibir_dados(lista_de_funcionarios, TAM);

    printf("-----------------------------------------------------------\n");
    printf("Digite o nome do funcionário que você quer buscar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    buscar_funcionarios_pelo_nome(lista_de_funcionarios, TAM, nome);

    printf("-----------------------------------------------------------\n");
    printf("Reajuste salarial\n\n");
    printf("Digite a matrícula funcional do funcionário: ");
    fgets(matricula_funcional, sizeof(matricula_funcional), stdin);
    matricula_funcional[strcspn(matricula_funcional, "\n")] = '\0';
    printf("Digite a porcentagem de reajuste: ");
    scanf("%f", &porcentagem);
    while(getchar() != '\n');
    reajustar_salario(lista_de_funcionarios, TAM, matricula_funcional, (1 + (porcentagem / 100)));

    media = calcular_media(lista_de_funcionarios, TAM);
    printf("-----------------------------------------------------------\n");
    printf("Media salarial dos funcionários: R$ %.2f\n", media);

    funcionario_com_maior_salario = buscar_maior_salario(lista_de_funcionarios, TAM);
    printf("-----------------------------------------------------------\n");
    printf("Dados de do funcionário com maior salário\n\n");
    printf("Matrícula funcional: %s\n", funcionario_com_maior_salario.matricula);
    printf("Nome: %s\n", funcionario_com_maior_salario.nome);
    printf("Salário: R$ %.2f\n", funcionario_com_maior_salario.salario);

    return 0;
}

void ler_dados(Funcionario funcionarios[], int tamanho) {
    printf("-----------------------------------------------------------\n");
    printf("Cadastre os dados dos funcionários\n");
    for(int i = 0; i < tamanho; i++) {
        printf("-----------------------------------------------------------\n");
        printf("Funcionário %d\n\n", i+1);
        printf("Matrícula funcional: ");
        fgets(funcionarios[i].matricula, sizeof(funcionarios[i].matricula), stdin);
        funcionarios[i].matricula[strcspn(funcionarios[i].matricula, "\n")] = '\0';

        printf("Nome: ");
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0';

        printf("Salário: R$ ");
        scanf("%f", &funcionarios[i].salario);

        while(getchar() != '\n');
    }
}

void exibir_dados(Funcionario funcionarios[], int tamanho) {
    printf("-----------------------------------------------------------\n");
    printf("Dados dos funcionários\n");
    for(int i = 0; i < tamanho; i++) {
        printf("-----------------------------------------------------------\n");
        printf("Funcionário %d\n\n", i+1);
        printf("Matrícula funcional: %s\n", funcionarios[i].matricula);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Salário: R$ %.2f\n", funcionarios[i].salario);
    }
}

void buscar_funcionarios_pelo_nome(Funcionario funcionarios[], int tamanho, char nome[50]) {
    int contador = 0;
    for(int i = 0; i < tamanho; i++) {
        if(strcmp(funcionarios[i].nome, nome) == 0) {
            contador++;
            printf("-----------------------------------------------------------\n");
            printf("Dados de %s - %d\n\n", nome, contador);
            printf("Matrícula funcional: %s\n", funcionarios[i].matricula);
            printf("Salário: R$ %.2f\n", funcionarios[i].salario);
        }
    }
    if(contador == 0) {
        printf("-----------------------------------------------------------\n");
        printf("Nenhum funcionário com o nome %s foi cadastrado!\n", nome);
    }
}

void reajustar_salario(Funcionario funcionarios[], int tamanho, char matricula_funcional[10], float reajuste) {
    for(int i = 0; i < tamanho; i++) {
        if(strcmp(funcionarios[i].matricula, matricula_funcional) == 0) {
            printf("-----------------------------------------------------------\n");
            printf("Salário reajustado de R$ %.2f para R$ %.2f\n", funcionarios[i].salario, funcionarios[i].salario*reajuste);
            funcionarios[i].salario *= reajuste;
            return;
        }
    }
    printf("-----------------------------------------------------------\n");
    printf("Nenhum funcionário com a matrícula %s foi cadastrado!\n", matricula_funcional);
}

float calcular_media(Funcionario funcionarios[], int tamanho) {
    float soma = 0.0;
    for(int i = 0; i < tamanho; i++) {
        soma += funcionarios[i].salario;
    }
    return soma / tamanho;
}

Funcionario buscar_maior_salario(Funcionario funcionarios[], int tamanho) {
    float maior_salario;
    int indice_do_maior_salario;
    for(int i = 0; i < tamanho; i++) {
        if(i == 0) {
            maior_salario = funcionarios[i].salario;
            indice_do_maior_salario = i;
            continue;
        }
        if(funcionarios[i].salario > maior_salario) {
            maior_salario = funcionarios[i].salario;
            indice_do_maior_salario = i;
        }
    }
    return funcionarios[indice_do_maior_salario];
}
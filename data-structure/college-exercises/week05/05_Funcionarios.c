#include <stdio.h>
#include <string.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome_cidade[50], UF[4];
} Cidade;

typedef struct {
    char rua[50];
    int numero;
    Cidade cidade;
} Endereco;

typedef struct {
    char nome[50];
    Data data_de_admissao;
    Endereco endereco;
} Funcionario;

int main() {
    Data data;
    Cidade cidade;
    Endereco endereco;
    Funcionario funcionario;

    printf("\t\tFuncionario\n\n");
    printf("Nome: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';

    printf("\nData de admissão\n");
    printf("Dia: ");
    scanf("%d", &data.dia);
    printf("Mês: ");
    scanf("%d", &data.mes);
    printf("Ano: ");
    scanf("%d", &data.ano);

    funcionario.data_de_admissao = data;
    
    while(getchar() != '\n');
    
    printf("\nEndereço\n");
    printf("Cidade: ");
    fgets(cidade.nome_cidade, sizeof(cidade.nome_cidade), stdin);
    cidade.nome_cidade[strcspn(cidade.nome_cidade, "\n")] = '\0';
    printf("UF: ");
    fgets(cidade.UF, sizeof(cidade.UF), stdin);
    cidade.UF[strcspn(cidade.UF, "\n")] = '\0';
    printf("Rua: ");
    fgets(endereco.rua, sizeof(endereco.rua), stdin);
    endereco.rua[strcspn(endereco.rua, "\n")] = '\0';
    printf("Número: ");
    scanf("%d", &endereco.numero);
    endereco.cidade = cidade;

    while(getchar() != '\n');

    funcionario.endereco = endereco;

    printf("\n\n-------------------------------------------------------\n\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("Data de admissão: %d/%d/%d\n", funcionario.data_de_admissao.dia, funcionario.data_de_admissao.mes, funcionario.data_de_admissao.ano);
    printf("Cidade: %s-%s\n", funcionario.endereco.cidade.nome_cidade, funcionario.endereco.cidade.UF);
    printf("Endereço: %s, %d\n", funcionario.endereco.rua, funcionario.endereco.numero);


    return 0;
}
#include <stdio.h>
#include <string.h>

typedef struct {
    int numero;
    char nome_titular[50];
    float saldo;
} Conta;

void ler_conta(Conta *c);
void depositar(Conta *c, float valor);
int sacar(Conta *c, float valor);
int tranferir(Conta *origem, Conta *destino, float valor);
void display(Conta *c, int n);

int main() {
    Conta conta1, conta2;
    ler_conta(&conta1);
    ler_conta(&conta2);
    depositar(&conta1, 3000);
    depositar(&conta2, 2000);
    display(&conta1, 1);
    display(&conta2, 2);
    int transferencia = tranferir(&conta1, &conta2, 3000);
    printf("----------------------------------------------\n");
    if(transferencia) 
        printf("Transferência feita com sucesso!\n");
    else
        printf("Não foi possível realizar a transferência!\n");
    display(&conta1, 1);
    display(&conta2, 2);


    return 0;
}

void ler_conta(Conta *c) {
    printf("----------------------------------------------\n");
    printf("Insira os dados da conta\n");
    printf("Número: ");
    scanf("%d", &c->numero);
    while(getchar() != '\n');
    printf("Nome do titular: ");
    fgets(c->nome_titular, sizeof(c->nome_titular), stdin);
    c->nome_titular[strcspn(c->nome_titular, "\n")] = '\0';
    printf("Saldo: R$ ");
    scanf("%f", &c->saldo);
    while(getchar() != '\n');
}

void depositar(Conta *c, float valor) {
    c->saldo += valor;
}

int sacar(Conta *c, float valor) {
    if(valor > c->saldo)
        return 0;
    c->saldo -= valor;
    return 1;
}

int tranferir(Conta *origem, Conta *destino, float valor) {
    if(sacar(origem, valor) == 0) 
        return 0;
    depositar(destino, valor);
    return 1;
}

void display(Conta *c, int n) {
    printf("----------------------------------------------\n");
    printf("Dados da conta %d\n\n", n);
    printf("Número: %d\nNome do Titular: %s\nSaldo: R$ %.2f\n", c->numero, c->nome_titular, c->saldo);
}
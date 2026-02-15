#include <stdio.h>

int main() {
    int qnt_maior_de_idade = 0, qnt_idosos = 0, total = 0, idade;
    double pct_idosos = 0;

    do {
        printf("Insira a idade da pessoa %d (insira um valor negativo para encerrar): ", total+1);
        scanf("%d", &idade);
        if(idade >= 21)
            qnt_maior_de_idade++;
        if(idade >= 65)
            qnt_idosos++;
        if(idade > 0)
            total++;
    } while(idade >= 0);
    if(total > 0)
        pct_idosos = ((double)qnt_idosos / total) * 100;
    printf("Quantidade de pessoas maiores de idade: %d\nPercentual de idosos: %.1f%%\n", qnt_maior_de_idade, pct_idosos);

    return 0;
}
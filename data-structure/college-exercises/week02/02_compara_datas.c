#include <stdio.h>

int main() {
    int dia1, dia2, mes1, mes2, ano1, ano2;
    printf("Digite o dia da data 1: ");
    scanf("%d", &dia1);
    printf("Digite o mes da data 1: ");
    scanf("%d", &mes1);
    printf("Digite o ano da data 1: ");
    scanf("%d", &ano1);
    printf("Data 1: %d/%d/%d\n", dia1, mes1, ano1);
    printf("--------------------------------------\n");
    printf("Digite o dia da data 2: ");
    scanf("%d", &dia2);
    printf("Digite o mes da data 2: ");
    scanf("%d", &mes2);
    printf("Digite o ano da data 2: ");
    scanf("%d", &ano2);
    printf("Data 2: %d/%d/%d\n", dia2, mes2, ano2);
    printf("--------------------------------------\n");
    if (ano1 == ano2 && mes1 == mes2 && dia1 == dia2) {
        printf("Datas iguais!\n");
    } else if(ano1 > ano2 || ((ano1 == ano2) && (mes1 > mes2)) || ((ano1 == ano2) && (mes1 == mes2) && (dia1 > dia2))) {
        printf("Cronologicamente a data 1 é maior (mais recente)!\n");
    } else {
        printf("Cronologicamente a data 2 é maior (mais recente)!\n");
    }

    return 0;
}

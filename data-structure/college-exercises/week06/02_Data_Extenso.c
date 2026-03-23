#include <stdio.h>

void dataPorExtenso(int dia, int mes, int ano);

int main() {
    dataPorExtenso(24, 1, 2006);

    return 0;
}

void dataPorExtenso(int dia, int mes, int ano) {
    char meses[12][50] = {
        "janeiro", "fevereiro", "março", "abril", "maio", "junho",
        "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
    };

    printf("%d de %s de %d", dia, meses[mes-1], ano);
}
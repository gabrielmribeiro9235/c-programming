#include <stdio.h>
#include <math.h>

int main() {
    int anos;
    float montante, capital_aplicado, taxa_de_juros;

    printf("Inisira o capital aplicado: R$ ");
    scanf("%f", &capital_aplicado);
    
    printf("Inisira a taxa de juros anual: ");
    scanf("%f", &taxa_de_juros);  
    
    printf("Inisira o tempo da aplicação em anos: ");
    scanf("%d", &anos);  

    montante = capital_aplicado * pow(1 + taxa_de_juros / 100, anos);

    printf("Montante: R$ %.2f", montante);

    return 0;
}
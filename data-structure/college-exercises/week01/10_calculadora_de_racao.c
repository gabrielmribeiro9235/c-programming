#include <stdio.h>

int main() {
    float peso_racao, consumo_diario, quantidade_consumida, sobra;
    
    printf("Insira a quantidade de ração (kg): ");
    scanf("%f", &peso_racao);
    
    printf("Insira o consumo diário de ração (g): ");
    scanf("%f", &consumo_diario);

    quantidade_consumida = consumo_diario * 0.005;
    sobra = peso_racao - quantidade_consumida;

    printf("\nQuantidade de ração consumida em 5 dias: %.2f kg\n", quantidade_consumida);
    if(sobra > 0) 
        printf("Sobraram %.2f kg de ração", sobra);
    else
        printf("Não há ração suficiente para 5 dias\n");

    return 0;
}
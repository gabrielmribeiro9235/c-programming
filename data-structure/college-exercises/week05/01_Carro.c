#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[20], marca[50], modelo[50];
    int anoFabricacao;
} Carro;


int main() {
    Carro carro;

    printf("Digite a placa do carro: ");
    fgets(carro.placa, sizeof(carro.placa), stdin);
    carro.placa[strcspn(carro.placa, "\n")] = '\0';
    
    printf("Digite a marca do carro: ");
    fgets(carro.marca, sizeof(carro.marca), stdin);
    carro.marca[strcspn(carro.marca, "\n")] = '\0';
    
    printf("Digite o modelo do carro: ");
    fgets(carro.modelo, sizeof(carro.modelo), stdin);
    carro.modelo[strcspn(carro.modelo, "\n")] = '\0';

    printf("Digite o ano de fabricação do carro: ");
    scanf("%d", &carro.anoFabricacao);

    printf("\n");

    printf("Placa do carro: %s\n", carro.placa);
    printf("Marca do carro: %s\n", carro.marca);
    printf("Modelo do carro: %s\n", carro.modelo);
    printf("Ano de fabricação do carro: %d\n", carro.anoFabricacao);

    return 0;
}
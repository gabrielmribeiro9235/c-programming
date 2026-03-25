#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[10], marca[50], modelo[50];
    int anoFabricacao;
} Carro;

Carro ler_dados(Carro car);
void exibir_dados(Carro car);
Carro atualizar_dados(Carro car);

int main() {
    Carro carro;

    carro = ler_dados(carro);

    exibir_dados(carro);
    
    carro = atualizar_dados(carro);
    
    exibir_dados(carro);

    return 0;
}

Carro ler_dados(Carro car) {
    printf("Placa do carro: ");
    fgets(car.placa, sizeof(car.placa), stdin);
    car.placa[strcspn(car.placa, "\n")] = '\0';

    printf("Marca do carro: ");
    fgets(car.marca, sizeof(car.marca), stdin);
    car.marca[strcspn(car.marca, "\n")] = '\0';

    printf("Modelo do carro: ");
    fgets(car.modelo, sizeof(car.modelo), stdin);
    car.modelo[strcspn(car.modelo, "\n")] = '\0';

    printf("Ano de fabricação: ");
    scanf("%d", &car.anoFabricacao);

    while(getchar() != '\n');

    return car;
}

void exibir_dados(Carro car) {
    printf("--------------------------------------\n");
    printf("Placa do carro: %s\n", car.placa);
    printf("Marca do carro: %s\n", car.marca);
    printf("Modelo do carr: %s\n", car.modelo);
    printf("Ano de fabricação: %d\n", car.anoFabricacao);
    printf("--------------------------------------\n");
}

Carro atualizar_dados(Carro car) {
    int flag_atulizacao;
    
    printf("Quer atualizar a placa do carro?\n");
    printf("1 para sim\n");
    printf("2 para não\n");
    printf("Sua escolha: ");
    scanf("%d", &flag_atulizacao);
    printf("--------------------------------------\n");
    while(getchar() != '\n');
    if(flag_atulizacao == 1) {
        printf("Placa do carro: ");
        fgets(car.placa, sizeof(car.placa), stdin);
        car.placa[strcspn(car.placa, "\n")] = '\0';
        printf("--------------------------------------\n");
    }
    
    printf("Quer atualizar a marca do carro?\n");
    printf("1 para sim\n");
    printf("2 para não\n");
    printf("Sua escolha: ");
    scanf("%d", &flag_atulizacao);
    printf("--------------------------------------\n");
    while(getchar() != '\n');
    if(flag_atulizacao == 1) {
        printf("Marca do carro: ");
        fgets(car.marca, sizeof(car.marca), stdin);
        car.marca[strcspn(car.marca, "\n")] = '\0';
        printf("--------------------------------------\n");
    }
    
    printf("Quer atualizar o modelo do carro?\n");
    printf("1 para sim\n");
    printf("2 para não\n");
    printf("Sua escolha: ");
    scanf("%d", &flag_atulizacao);
    printf("--------------------------------------\n");
    while(getchar() != '\n');
    if(flag_atulizacao == 1) {
        printf("Modelo do carro: ");
        fgets(car.modelo, sizeof(car.modelo), stdin);
        car.modelo[strcspn(car.modelo, "\n")] = '\0';
        printf("--------------------------------------\n");
    }
    
    printf("Quer atualizar o ano de fabricação do carro?\n");
    printf("1 para sim\n");
    printf("2 para não\n");
    printf("Sua escolha: ");
    scanf("%d", &flag_atulizacao);
    while(getchar() != '\n');
    if(flag_atulizacao == 1) {
        printf("--------------------------------------\n");
        printf("Ano de fabricação: ");
        scanf("%d", &car.anoFabricacao);
    }
    
    return car;
}
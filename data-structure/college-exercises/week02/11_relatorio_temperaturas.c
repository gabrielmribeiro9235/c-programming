#include <stdio.h>

int main() {
    float temperatura, maior, menor, total = 0.0, media;

    for(int i = 1; i <= 7; i++) {
        printf("Temperatura %d/7: ", i);
        scanf("%f", &temperatura);
        if(i == 1) {
            maior = temperatura;
            menor = temperatura;
        } else {
            if(temperatura > maior) {
                maior = temperatura;
            }
            if(temperatura < menor) {
                menor = temperatura;
            }
        }
        total += temperatura;
    }
    media = total / 7;

    printf("Média das temperaturas: %.1f °C\nTemperatura mais alta: %.1f °C\nTemperatura mais baixa: %.1f °C", media, maior, menor);


    return 0;
}
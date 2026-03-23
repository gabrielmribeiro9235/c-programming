#include <stdio.h>

float farenheit_para_celcius(float graus_f);

int main() {
    float farenheit, celcius;
    
    printf("Insira a temperatura em °F: ");
    scanf("%f", &farenheit);
    
    celcius = farenheit_para_celcius(farenheit);

    printf("\n%.1f °F valem %.1f °C\n", farenheit, celcius);

    return 0;
}

float farenheit_para_celcius(float graus_f) {
    return (graus_f - 32) * ((float) 5/9);
}
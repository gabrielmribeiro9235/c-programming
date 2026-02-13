#include <stdio.h>

int main() 
{
    float celcius, farenheit;

    printf("Insira a temperatura em °F: ");
    scanf("%f", &farenheit);

    celcius = (farenheit - 32) / 1.8;
    printf("Temperatura em °C: %.0f\n", celcius);
    
    return 0;
}
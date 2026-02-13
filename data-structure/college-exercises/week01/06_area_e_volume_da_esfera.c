#include <stdio.h>
#define PI 3.14159

int main() {
    float raio, area, volume;
    
    printf("Insira o valor do raio da esfera: ");
    scanf("%f", &raio);

    area = 4 * PI * raio * raio;
    volume = ((float)4 / 3) * PI * raio * raio * raio;

    printf("Área: %.5f u.a\n", area);
    printf("Volume: %.5f u.v\n", volume);
    
    return 0;
}
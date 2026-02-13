#include <stdio.h>

int main() 
{
    float base, altura, area;
    printf("Insira a altura: ");
    scanf("%f", &altura);
    
    printf("Insira a largura: ");
    scanf("%f", &base);
    
    area = base * altura;
    printf("Área: %.2fm²\n", area);    
    
    return 0;
}

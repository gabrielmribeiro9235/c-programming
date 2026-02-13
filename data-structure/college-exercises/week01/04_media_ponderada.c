#include <stdio.h>

int main() 
{
    float nota1, nota2, nota3, p1, p2, p3, media;

    printf("Insira a primeira nota: ");
    scanf("%f", &nota1);

    printf("Insira o peso da primeira prova: ");
    scanf("%f", &p1);

    printf("-----------------------------\n");

    printf("Insira a segunda nota: ");
    scanf("%f", &nota2);

    printf("Insira o peso da segunda prova: ");
    scanf("%f", &p2);

    printf("-----------------------------\n");
    
    printf("Insira a terceira nota: ");
    scanf("%f", &nota3);
    
    printf("Insira o peso da terceira prova: ");
    scanf("%f", &p3);

    printf("-----------------------------\n");

    media = (nota1*p1 + nota2*p2 + nota3*p3) / (p1+ p2 + p3);
    printf("A média do aluno foi: %.2f\n", media);

    return 0;
}
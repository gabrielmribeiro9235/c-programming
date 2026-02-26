#include <stdio.h>

int main() {
    float salary_vector[10], soma = 0, media = 0;
    
    for(int i = 0; i < 10; i++) {
        printf("Salário %d: R$ ", i+1);
        scanf("%f", &salary_vector[i]);
    }
    
    for(int i = 0; i < 10; i++) {
        soma += salary_vector[i];
    }
    
    media = soma / 10;
    printf("\nMédia dos salários: R$ %.2f\n\nNovos salários:\n\n", media);

    for(int i = 0; i < 10; i++) {
        if(salary_vector[i] > media)
            salary_vector[i] *= 1.05;
        else
            salary_vector[i] *= 1.1;
        
        printf("Novo salário %d: R$ %.2f\n", i+1, salary_vector[i]);
    }

    return 0;
}
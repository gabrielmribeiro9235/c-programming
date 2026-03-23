#include <stdio.h>
#include <math.h>
#define TAM 10

void ler_vetor(float vetor[], int tamanho);
void exibir_vetor(float vetor[], int tamanho);
float calcular_media(float vetor[], int tamanho);
float calcular_variancia(float vetor[], int tamanho, float media);
float calcular_desvio_padrao(float variancia);
void atualizar_vetor(float vetor[], int tamanho, float media, float aumento);

int main() {
    float vetor[TAM];
    float media, variancia, desvio_padrao, aumento;

    ler_vetor(vetor, TAM);
    exibir_vetor(vetor, TAM);
    media = calcular_media(vetor, TAM);
    printf("Média dos valores: %.2f\n", media);
    variancia = calcular_variancia(vetor, TAM, media);
    printf("-------------------------------------------------------------------------\n");
    printf("Variancia dos valores: %.2f\n", variancia);
    desvio_padrao = calcular_desvio_padrao(variancia);
    printf("-------------------------------------------------------------------------\n");
    printf("Desvio padrão dos valores: %.2f\n", desvio_padrao);
    
    printf("-------------------------------------------------------------------------\n");
    printf("Insira o percentual de aumento para os valores abaixo da média: ");
    scanf("%f", &aumento);
    atualizar_vetor(vetor, TAM, media, aumento/100);
    exibir_vetor(vetor, TAM);
}

void ler_vetor(float vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("Insira o valor %d: ", i+1);
        scanf("%f", &vetor[i]);
    }
}

void exibir_vetor(float vetor[], int tamanho) {
    printf("-------------------------------------------------------------------------\n");
    for(int i = 0; i < tamanho; i++) {
        printf("Valor %d: %.2f\n", i+1, vetor[i]);
    }
    printf("-------------------------------------------------------------------------\n");
}

float calcular_media(float vetor[], int tamanho) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return (float) soma / tamanho;
}

float calcular_variancia(float vetor[], int tamanho, float media) {
    float somatorio = 0.0;
    for(int i = 0; i < tamanho; i++) {
        somatorio += (vetor[i] - media) * (vetor[i] - media);
    }
    return somatorio / tamanho;
}

float calcular_desvio_padrao(float variancia) {
    return sqrt(variancia);
}

void atualizar_vetor(float vetor[], int tamanho, float media, float aumento) {
    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] < media)
            vetor[i] += vetor[i] * aumento;
    }
}
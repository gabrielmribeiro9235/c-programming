#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define num 3

struct pessoas{
	char nome[50];
	int idade;
	float peso;
};

typedef struct pessoas pessoa;

int main(){
	setlocale(LC_ALL, "pt_BR");
	pessoa lista[num];
	int i;
	
	for(i=0; i<num; i++){
		printf("------Pessoa %d------\n", i+1);
		printf("Nome: ");
		scanf("%49[^\n]s", &lista[i].nome);
		fflush(stdin);
		printf("Idade: ");
		scanf("%d", &lista[i].idade);
		fflush(stdin);
		printf("Peso: ");
		scanf("%f", &lista[i].peso);
		fflush(stdin);	
	}
	
	system("cls");
	
	puts("Dados inserido:");
	for(i=0; i<num; i++){
		puts("-------------------------");		
		printf("\tPessoa %d\n", i+1);
		printf("Nome: %s\n", lista[i].nome);
		printf("Idade: %d anos\n", lista[i].idade);
		printf("Peso: %.2f kg\n", lista[i].peso);
	}
	puts("-------------------------\n");
	
}

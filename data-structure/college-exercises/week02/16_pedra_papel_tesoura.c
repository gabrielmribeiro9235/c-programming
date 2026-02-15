#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int computador, jogador;
    srand( (unsigned)time(NULL) );
    do {
        printf("\n1. Pedra\n2. Papel\n3. Tesoura\n0. Encerrar o programa\n");
        printf("Sua escolha: ");
        scanf("%d", &jogador);
        computador = ( rand() % 3 ) + 1;
        if(jogador == 1 || jogador == 2 || jogador == 3){
            if(jogador == computador) {
                if(jogador == 1)
                    printf("\nVocê: Pedra\nComputador: Pedra\nResultado: Empate\n");
                else if(jogador == 2)
                    printf("\nVocê: Papel\nComputador: Papel\nResultado: Empate\n");
                else
                    printf("\nVocê: Tesoura\nComputador: Tesoura\nResultado: Empate\n");
            } else if((jogador == 1 && computador == 2) || (jogador == 2 && computador == 3) || (jogador == 3 && computador == 1)) {
                if(jogador == 1)
                    printf("\nVocê: Pedra\nComputador: Papel\nResultado: Computador ganhou\n");
                else if(jogador == 2)
                    printf("\nVocê: Papel\nComputador: Tesoura\nResultado: Computador ganhou\n");
                else
                    printf("\nVocê: Tesoura\nComputador: Pedra\nResultado: Computador ganhou\n");
            } else {
                if(jogador == 1)
                    printf("\nVocê: Pedra\nComputador: Tesoura\nResultado: Você ganhou\n");
                else if(jogador == 2)
                    printf("\nVocê: Papel\nComputador: Pedra\nResultado: Você ganhou\n");
                else
                    printf("\nVocê: Tesoura\nComputador: Papel\nResultado: Você ganhou\n");            
            }
        }
    } while(jogador != 0);

    return 0;
}
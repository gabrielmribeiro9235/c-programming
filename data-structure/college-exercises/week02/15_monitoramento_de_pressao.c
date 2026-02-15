#include <stdio.h>

int main() {
    int pacientes, dias, soma_sistolica, soma_diastolica;
    float media_sistolica, media_diastolica, sistolica, diastolica;

    do {
        printf("Quantos pacientes quer cadastrar? ");
        scanf("%d", &pacientes);
    } while (pacientes < 0);
    
    for(int i = 1; i <= pacientes; i++) {
        do {
            printf("\nQuantos dias de monitoramento o Paciente %d teve? ", i);
            scanf("%d", &dias);
        } while (dias <= 0);
        media_diastolica = 0;
        media_sistolica = 0;
        soma_sistolica = 0;
        soma_diastolica = 0;
        for(int j = 1; j <= dias; j++) {
            printf("\n");
            do {
                printf("Insira a pressão sistólica do dia %d: ", j);
                scanf("%f", &sistolica);
            } while(sistolica < 0);
            soma_sistolica += sistolica;

            do {
                printf("Insira a pressão diastólica do dia %d: ", j);
                scanf("%f", &diastolica);
            } while(diastolica < 0);
            soma_diastolica += diastolica;
        } 
        media_diastolica = (float)soma_diastolica / dias;  
        media_sistolica = (float)soma_sistolica / dias; 
        printf("\nSituação do Paciente %d: ", i);
        if(media_sistolica <= 12 && media_diastolica <= 8)
            printf("Normal\n"); 
        else
            printf("Hipertenso\n");
    }

    return 0;
}
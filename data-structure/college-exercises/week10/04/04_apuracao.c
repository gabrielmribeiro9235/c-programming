#include <stdio.h>

void apurar_votos_validos(char *path);
void apurar_votos_nulos(char *path);

int main() {
    char *path = "votos.txt";
    apurar_votos_validos(path);
    apurar_votos_nulos(path);
    return 0;
}

void apurar_votos_validos(char *path) {
    FILE *file = fopen(path, "r");
    if(file == NULL) {
        printf("Arquivo não encontrado!");
        return;
    }
    int voto, A = 0, B = 0, C = 0;
    while(fscanf(file, "%d", &voto) == 1) {
        if(voto == 100){
            A++;
            continue;
        }
        if(voto == 200){
            B++;
            continue;
        }
        if(voto == 300){
            C++;
            continue;
        }
    }
    printf("-------------------------\n");
    printf("Candidato A: %d\n", A);
    printf("Candidato B: %d\n", B);
    printf("Candidato C: %d\n", C);
}

void apurar_votos_nulos(char *path) {
    FILE *file = fopen(path, "r");
    if(file == NULL) {
        printf("Arquivo não encontrado!");
        return;
    }
    int voto, nulo = 0;
    while(fscanf(file, "%d", &voto) == 1) {
        if(voto != 100 && voto != 200 && voto != 300)
        nulo++;
    }
    printf("-------------------------\n");
    printf("Votos nulos: %d\n", nulo);
}

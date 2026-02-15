#include <stdio.h>

int main() {
    double altura_chico = 1.5, altura_ze = 1.1, crescimento_chico = 0.02, crescimento_ze = 0.03;
    int tempo = 0;
    
    while (altura_chico >= altura_ze) {
        altura_chico += crescimento_chico;
        altura_ze += crescimento_ze;
        tempo++;
    }
    
    printf("Vai demorar %d anos para Zé ser maior que Chico\n", tempo);

    return 0;
}

#include <stdio.h>

void formatar_CPF(char CPF[12]);

int main() {
    formatar_CPF("53903280860");

    return 0;
}

void formatar_CPF(char CPF[12]) {
    for(int i = 0; i < 11; i++) {
        if(i == 3 || i == 6) {
            printf(".%c", CPF[i]);
            continue;
        } 
        if(i == 9) {
            printf("-%c", CPF[i]);
            continue;
        }
        printf("%c", CPF[i]);        
    }
};

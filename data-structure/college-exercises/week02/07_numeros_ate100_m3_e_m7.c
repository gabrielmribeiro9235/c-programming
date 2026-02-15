#include <stdio.h>

int main() {
    for(int i = 0; i <= 100; i = i + 21) {
        if(i == 0) 
            continue;
        else
            printf("%d ", i);
    }
    
    return 0;
}
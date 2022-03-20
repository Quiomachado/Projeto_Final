#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    int awn, input, num1, num2;
    time_t t1;

    srand((unsigned) time (&t1));
    printf("\n");
    num1 = rand() % 9 + 1;
    num2 = rand() % 9 + 1;
    printf("Quanto e %d a multiplicar por %d?\n", num1, num2);
    scanf("%d", &input);
    awn = num1 * num2;
    while(input != awn){
        printf("A sua resposta esta errada tente de novo: \n");
        scanf("%d", &input);
        if(input == 0){
            return EXIT_SUCCESS;
        }
    }
    if(input == awn){
        printf("A sua resposta esta correta!");
    }
    return EXIT_SUCCESS;
}
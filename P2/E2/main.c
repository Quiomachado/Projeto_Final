#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int mes;
    printf("Introduza o numero do mes: ");
    scanf("%i", &mes);
    switch (mes) {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10:
        case 12:
            printf("O mes tem 31 dias.");
            break;
        case 4 :
        case 6 :
        case 9 :
        case 11:
            printf("O mes tem 30 dias.");
            break;
        case 2 :
            printf("O mes tem 29 dias.");
            break;
        default:
        printf("Introduza um valor entre 1 e 12 para tentar de novo ou um valor fora desse intervalo para fechar.");
        scanf("%d", &mes);
        }
    return 0;
}
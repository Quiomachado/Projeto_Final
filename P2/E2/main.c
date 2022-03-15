#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int mes;
    printf("Introduza o numero do mes: ");
    scanf("%i", &mes);
    do{
        switch (mes) {
            case 1 :
            case 3 :
            case 5 :
            case 7 :
            case 8 :
            case 10:
            case 12:
                printf("O mes %d tem 31 dias.\n", mes);
                break;
            case 4 :
            case 6 :
            case 9 :
            case 11:
                printf("O mes %d tem 30 dias.\n", mes);
                break;
            case 2 :
                printf("O mes %d tem 29 dias.\n", mes);
                break;
        }
            printf("Introduza um valor entre 1 e 12 para tentar de novo ou um valor fora desse intervalo para terminar: \n");
            scanf("%d", &mes);
    }while ((mes<=12)&&(mes>=1));
    return 0;
}
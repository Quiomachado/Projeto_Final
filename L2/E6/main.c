#include <stdio.h>

int main() {
    int mes;
    printf("Introduza o numero do mes: ");
    scanf("%d", &mes);
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
            printf("O mes tem 28 dias se nao for um ano bissexto ou 29 dias se o ano for bissexto.");
            break;
        default:
            printf("Introduza um numero entre 1 e 12.");
    }
}
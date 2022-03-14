#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char a1, a2, a3;
    int n1, n2, n3, nf;
    printf("Escreva o primeiro carater:");
    scanf(" %c", &a1);
    printf("Introduza o segundo carater:");
    scanf(" %c", &a2);
    printf("Introduza o terceiro carater:");
    scanf(" %c", &a3);
    n1 = a1 - '0';
    n2 = a2 - '0';
    n3 = a3 - '0';
    nf = (n1 * 200) + (n2 * 20) + (n3*2);
    printf("O seu numero e %i", nf);
} 
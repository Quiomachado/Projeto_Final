#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int a1, a2, a3, n1, n2, n3;
    printf("Escreva o primeiro digito:");
    scanf("%d", &a1);
    printf("Escreva o segundo digito:");
    scanf("%d", &a2);
    printf("Escreva o terceiro digito:");
    scanf("%d", &a3);
    n1 = a1 * 2;
    n2 = a2 * 2;
    n3 = a3 * 2;
    printf("O seu numero e %d%d%d", n1, n2, n3);
}

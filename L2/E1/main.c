#include <stdio.h>

int main() {
    int n, s, m, h;
    printf("Introduza o numero de segundos que pretende converter:");
    scanf("%d", &n);
    h = n/3600;
    m = (n%3600)/60;
    s = (n%3600)%60;
    printf("%d segundos sao\n", n);
    printf("%d horas\n", h);
    printf("%d minutos\n", m);
    printf("e %d segundos\n", s);
}
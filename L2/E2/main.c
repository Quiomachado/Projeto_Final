#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int r, n1, n2, h1, h2, m1, m2, s1, s2, hr, mr, sr;
    printf("Introduza as horas do primeiro horario:\n");
    scanf("%d", &h1);
    printf("Introduza os minutos do primeiro horario:\n");
    scanf("%d", &m1);
    printf("Introduza os segundos do primeiro horario:\n");
    scanf("%d", &s1);
    printf("Introduza as horas do segundo horario:\n");
    scanf("%d", &h2);
    printf("Introduza os minutos do segundo horario:\n");
    scanf("%d", &m2);
    printf("Introduza os segundos do segundo horario:\n");
    scanf("%d", &s2);
    n1 = (h1*3600) + (m1*60) + s1;
    n2 = (h2*3600) + (m2*60) + s2;
    if(n1>=n2) {
        r = n1 - n2;
        hr = r / 3600;
        mr = (r % 3600) / 60;
        sr = (r % 3600) % 60;
        printf("%d horas\n", hr);
        printf("%d minutos\n", mr);
        printf("e %d segundos\n", sr);
    }else{
        printf("o primeiro horario e menor que o segundo");
    }
}

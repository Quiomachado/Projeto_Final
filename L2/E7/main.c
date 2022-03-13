#include <stdio.h>

int main() {
    double ni;
    int l;
    printf("Introduza n:");
    scanf("%d", &l);
    printf("Introduza o numero:");
    scanf("%lf", &ni);
    printf("%.*f",l, ni);

    return 0;
}

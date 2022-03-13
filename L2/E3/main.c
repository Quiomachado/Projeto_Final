#include <stdio.h>
#include <math.h>
#define g 9.8

int main() {
    double h, v0, ang, c,t, rang;
    printf("Introduza o angulo de partida.\n");
    scanf("%lf", &ang);
    printf("Introduza a velocidade inicial.\n");
    scanf("%lf", &v0);
    printf("Introduza a altura do teto.\n");
    scanf("%lf", &t);
    rang = ang * (M_PI/180.0);
    h = (pow(v0,2)*pow(sin(rang),2))/(2*g);
    c = (pow(v0, 2)*sin(2*rang))/g;
    if(h>t) {
        printf("O projetil bate no teto\n");
    }else{
        printf("O centro do balde deve estar a %f metros", c);
    }
}

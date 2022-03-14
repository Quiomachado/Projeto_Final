#include <stdio.h>
#include <math.h>
#define g 9.8
#define PI 3.14

int main() {
    double v0, d, rang, c, r, cp, cl, h, ang;
    printf("Introduza a velocidade inicial:");
    scanf("%lf", &v0);
    printf("Introduza o diametro do cesto:");
    scanf("%lf", &d);
    printf("Introduza a distancia ao centro do cesto:");
    scanf("%lf", &c);
    r = d/2.0;
    ang = 0.0;
    cp = c - r;
    cl = c + r;
    /*c = ((pow(v0, 2)*sin(2*rang))/g);*/
    while (ang <= 90){
        rang = ang * (PI/180);
        h=(pow(v0, 2)*sin(2*rang))/g;
        if((cp<=h) && (h<=cl)) {
            printf("\nO valor do angulo pode ser %.2f.", ang);
        }
    ang=ang +0.1;
    }
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define RADIO 3000000000
#define MICRO 3*pow(10, 12)
#define INFRARED 4.3*pow(10, 14)
#define VISIBLE 7.5*pow(10, 14)
#define ULTRA 3*pow(10, 17)
#define RAYS 3*pow(10, 19)

int main() {
    double light;
    printf("Introduza a frequencia:");
    scanf("%lf", &light);
    if(light<RADIO){
        printf("Essa frequencia pertence as ondas de radio.");
    }else if(RADIO<=light<MICRO){
        printf("Essa frequencia pertence as micro ondas.");
    }else if(MICRO<=light<INFRARED) {
        printf("Essa frequencia pertence aos infravermelhos.");
    }else if(INFRARED<=light<VISIBLE) {
        printf("Essa frequencia pertence a luz visivel.");
    }else if(VISIBLE<=light<ULTRA) {
        printf("Essa frequencia pertence a luz ultravioleta.");
    }else if(ULTRA<=light<RAYS) {
        printf("Essa frequencia pertence aos raios x.");
    }else{
        printf("Essa frequencia pertence aos raios gama.");
    }
}
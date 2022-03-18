#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    int num, i;
    double r, med, som, div;
    i=1;
    div = 0;
    printf("Introduza o seu numero: ");
    scanf("%d", &num);
    while(num>=i){
        r = num%i;
        if(r==0){
            printf("%d ", i);
            som += i;
            div++;
        }
    i++;
    }
    med=(double)som/div;
    printf("\nA media e: %.3f", med);
}
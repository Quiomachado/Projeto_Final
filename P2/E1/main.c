#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    int num, i;
    double r;
    i=1;
    printf("Introduza o seu numero: ");
    scanf("%d", &num);
    while(num>=i){
        r = num%i;
        if(r==0){
            printf("%d ", i);
        }
    i++;
    }
}
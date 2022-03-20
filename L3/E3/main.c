#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int calc_hist(int vect[], int size, int k);
int main (){

    return EXIT_SUCCESS;
}

int calc_hist(int vect[], int size, int k){
    int i, j, l;
    int largura, max, min;
    min=max=vect[0];
    for(i=1; i<size;i++){
        if(min>vect[i])
            min=vect[i];
        if(max<vect[i])
            max=vect[i];
    }
    largura=(max-min)/k;
    int hist[k][largura];
    for(l=0; l<k; l++){
        for(j=0;j<largura;j++){
            
        }
    }
}
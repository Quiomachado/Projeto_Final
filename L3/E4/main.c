#include <stdio.h>
#include <stdlib.h>

void ini_vector();
int main(){
    return EXIT_SUCCESS;
}

void ini_vector(){
    int n, i;
    printf("Introduza quantos numeros inteiros pretende introduzir: \n");
    scanf("%d", &n);
    int vect[n];
    for(i=0; i<n; i++){
        printf("Introduza o %d valor:\n", i+1);
        scanf("%d", &vect[i]);
        if(vect[i]<0 || vect[i]>9){
            printf("Introduza um valor entre 1 e 9:\n");
            scanf("%d", &vect[i]);
        }
    }
}


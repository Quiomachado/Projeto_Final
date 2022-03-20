#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256

int *ini_vector(int n);
void coder(int n, int vect[]);
int main(){
    int n;
    printf("Introduza quantos numeros inteiros prentende introduzir:\n");
    scanf("%d", &n);
    int* vector;
    vector = ini_vector(n);
    coder(n, vector);
    return EXIT_SUCCESS;
}

int *ini_vector(int n){
    int i;
    static int* vect;
    vect = malloc(MAX_SIZE * sizeof(int));
    for(i=0; i<n; i++){
        printf("Introduza o %d valor:\n", i+1);
        scanf("%d", &vect[i]);
        if((vect[i]<0) || (vect[i]>9)){
            printf("Introduza um valor entre 1 e 9:\n");
            scanf("%d", &vect[i]);
        }
    }
    return vect;
}

void coder(int n, int vect[]){
    int str[n];
    int i,j,l;
    int aux;
    int count = 1;
    char awnser[n];
    for(i=0;i<n;i++){
        aux=0;
        count=1;
        for(j=i+1;j<n;j++){
            if(vect[i]==vect[j]){
                aux=1;
            }
        }
        if(aux == 1){
            //printf("%d", vect[i]);
            count++;
            printf("%d%d ", count, vect[i]);
        }
        if(aux == 0){
            printf("%d%d ", count, vect[i]);
        }
    }
}
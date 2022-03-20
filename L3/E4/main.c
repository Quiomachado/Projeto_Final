#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256

int *ini_vector(int n);
void str_dig(int n, int vect[]);
int main(){
    int n;
    printf("Introduza quantos numeros inteiros prentende introduzir:\n");
    scanf("%d", &n);
    int* vector;
    vector = ini_vector(n);
    str_dig(n, vector);
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
    int i,j;
    char awnser[n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

void ini_vector(int, int []);
void coder(int , int [], int []);
void decoder(int []);
int main(){
    int n;
    int vect[MAX_SIZE], vectcod[MAX_SIZE];
    printf("Introduza quantos numeros inteiros prentende introduzir:\n");
    scanf("%d", &n);
    ini_vector(n, vect);
    coder(n, vect, vectcod);
    decoder(vectcod);
    return EXIT_SUCCESS;
}

void ini_vector(int n, int vect[]){
    int i;
    for(i=0; i<n; i++){
        printf("Introduza o %d valor:\n", i+1);
        scanf("%d", &vect[i]);
        if((vect[i]<0) || (vect[i]>9)){
            printf("Introduza um valor entre 1 e 9:\n");
            scanf("%d", &vect[i]);
        }
    }
    return;
}

void coder(int n, int vect[], int vectcod[]){
    int i=0, counter=1, j=0;
    for(i=0; i<n;i++){
        if(vect[i]==vect[i+1]){
            counter++;
        }else{
            vectcod[j] = counter;
            vectcod[j+1] = vect[i];
            printf("%d%d", vectcod[j], vectcod[j+1]);
            j += 2;
            counter = 1;
        }
    }
    printf("\n");
    return;
}

void decoder(int vectcod[]){
    int i=0, j=0;
    while(vectcod[i] != '\0'){
        for(j=vectcod[i]; j>0; j--){
            printf("%d", vectcod[i+1]);
        }
        i+=2;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

void load_vect(char [MAX_SIZE][MAX_SIZE], int );
void sort_vect(char [MAX_SIZE][MAX_SIZE], int );
void print_vect(char [MAX_SIZE][MAX_SIZE], int );

int main(){
    char str_vect[MAX_SIZE][MAX_SIZE];
    int n;
    printf("Introduza o numero de palavras a ler:\n");
    scanf("%d", &n);
    load_vect(str_vect, n);
    sort_vect(str_vect, n);
    print_vect(str_vect, n);
    return EXIT_SUCCESS;
}

void load_vect(char str_vect[MAX_SIZE][MAX_SIZE], int n){
    int i;
    printf("Introduza as suas palavras separadas por ENTER:\n");
    for(i=0;i<n;i++){
        scanf("%s", str_vect+i);
    }
    return;
}

void sort_vect(char str_vect[MAX_SIZE][MAX_SIZE], int n){
    int i, j, k;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(strcmp(str_vect[j], str_vect[j+1])> 0){
                char temp[MAX_SIZE];
                strcpy(temp,str_vect[j]);
                strcpy(str_vect[j],str_vect[j+1]);
                strcpy(str_vect[j+1],temp);
            }
        }
    }
    return;
}

void print_vect(char str_vect[MAX_SIZE][MAX_SIZE], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%s ", str_vect+i);
    }
    return;
}
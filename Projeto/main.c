#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void initablueiro(char [16][16], int);

int main(){
    char tabuleiro[16][16];
    int n;
    printf("Introduza o numero de linhas e colunas, este numero deve ser impar e estar entre 7 e 15:\n");
    scanf("%d", &n);
    while((n<7 || n>15) || ((n%2)==0)){
        printf("Nao introduzio um valor valido, introduza um valor impar entre 7 e 15:\n");
        scanf("%d", &n);
    }
    initablueiro(tabuleiro, n);
}

void initablueiro(char tabuleiro[16][16], int n){
    int i, k;
    for(i=0;i<=n+1;i++){
        for(k=0;k<=n+1;k++){
            tabuleiro[i][k]='.';
        }
    }
    for(i=0;i<n;i++){
        tabuleiro[i][0]= i +'1';
        if(i+'1'>=58){
            tabuleiro[i][0]='i';
        }
    }
    for(i=1;i<=n;i++){
        tabuleiro[n][i]=i+'@';
    }
    for(i=0;i<=n+1;i++){
        for(k=1;k<=n+1;k++){
            if(i+1==k || n-i==k){
                tabuleiro[i][k]='2';
            }

        }
    }
    for(i=0;i<=n;i++){
        for(k=0;k<=n;k++){
            printf("%c ", tabuleiro[i][k]);
        }
        printf("\n");
    }
}
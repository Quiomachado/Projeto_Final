#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void initablueiro(char [16][16],char [16],int [16], int);
void printabuleiro(char [16][16],char [16],int [16], int);

int main(){
    char tabuleiro[16][16];
    int eixonum[16];
    char eixoletras[16];
    int n;
    printf("Introduza o numero de linhas e colunas, este numero deve ser impar e estar entre 7 e 15:\n");
    scanf("%d", &n);
    while(n<7 || n>15 || (n%2)==0){
        printf("Nao introduzio um valor valido, introduza um valor impar entre 7 e 15:\n");
        scanf("%d", &n);
    }
    initablueiro(tabuleiro, eixoletras, eixonum, n);
    printabuleiro(tabuleiro, eixoletras, eixonum, n);
}

void initablueiro(char tabuleiro[16][16],char eixoletras[16], int eixonum[16], int n){
    int i, k;
    for(i=1;i<=n;i++){
        for(k=1;k<=n;k++){
            tabuleiro[i][k]='.';
        }
    }
    for(i=0;i<=n;i++){
        eixonum[i]=i;
        eixoletras[i]=i+'@';
    }
    for(i=1;i<=n;i++){
        for(k=1;k<=n;k++){
            if(i==k || n-i==k-1){
                tabuleiro[i][k]='2';
            }
            if(i==1 && k==1 || i==1 && k==n || i==n && k==1 || i==n && k==n){
                tabuleiro[i][k]='$';
            }
            if(((k==(n/2)+1)&&(i==1 || i==n))||((i==(n/2)+1)&&(k==1 || k==n))){
                tabuleiro[i][k]='3';
            }
            if((((k==(n/2))||k==((n/2)+2))&&(i==2 || i==n-1))||(((i==(n/2))||i==((n/2)+2))&&(k==2 || k==n-1))){
                tabuleiro[i][k]='#';
            }
        }
    }
    /*for(i=1;i<=n;i++){
        if(i<=n){
            if(i<=9){
                printf(" %d ", eixonum[i]);
            }else{
                printf("%d ", eixonum[i]);
            }
        }
        for(k=1;k<=n;k++){
            printf("%c ", tabuleiro[i][k]);
        }
        printf("\n");
    }
    for(i=n;i<=n;i++){
        printf("   ");
        for(k=1;k<=n;k++){
            printf("%c ", eixoletras[k]);
        }
    }*/
}

void printabuleiro(char tabuleiro[16][16],char eixoletras[16], int eixonum[16], int n){
    int i, k;
    for(i=1;i<=n;i++){
        if(i<=n){
            if(i<=9){
                printf(" %d ", eixonum[i]);
            }else{
                printf("%d ", eixonum[i]);
            }
        }
        for(k=1;k<=n;k++){
            printf("%c ", tabuleiro[i][k]);
        }
        printf("\n");
    }
    for(i=n;i<=n;i++){
        printf("   ");
        for(k=1;k<=n;k++){
            printf("%c ", eixoletras[k]);
        }
    }
}
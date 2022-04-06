#include "Projeto_Final.h"

void printabuleiro(char tabuleiro[16][16],char eixoletras[16], int eixonum[16], int n){
    int i, k;
    printf("\nEstado atual do tabuleiro:\n");
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
    printf("\n");
}

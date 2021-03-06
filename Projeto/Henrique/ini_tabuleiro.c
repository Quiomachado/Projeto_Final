#include "Projeto_Final.h"

void initablueiro(char *tabuleiro[16],char eixoletras[16], int eixonum[16], int n){
    int i, k;
    for(i=1;i<=n;i++)//Para as seguintes coordenadas imprimir: '.'
    {
        tabuleiro[i] = (char *) calloc(MAX_SIZE, sizeof(char));
        for(k=1;k<=n;k++)
        {
            tabuleiro[i][k]='.';
        }
    }
    for(i=0;i<=n;i++)
    {
        eixonum[i]=i;
        eixoletras[i]=i+'@'; //Alterar o int para letras
    }
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n;k++)
        {
            if(i==k || n-i==k-1){ //Para as seguintes coordenadas imprimir: '2'
                tabuleiro[i][k]='2';
            }
            if(((i==1) && (k==1)) || ((i==1) && (k==n)) || ((i==n) && (k==1)) || ((i==n) && (k==n))){ //Para as seguintes coordenadas imprimir: '$'
                tabuleiro[i][k]='$';
            }
            if(((k==(n/2)+1)&&(i==1 || i==n))||((i==(n/2)+1)&&(k==1 || k==n))){ //Para as seguintes coordenadas imprimir: '3'
                tabuleiro[i][k]='3';
            }
            if((((k==(n/2))||k==((n/2)+2))&&(i==2 || i==n-1))||(((i==(n/2))||i==((n/2)+2))&&(k==2 || k==n-1))){ //Para as seguintes coordenadas imprimir: '#'
                tabuleiro[i][k]='#';
            }
        }
    }
}

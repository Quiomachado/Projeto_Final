#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void initablueiro(char [16][16],char [16],int [16], int);
void printabuleiro(char [16][16],char [16],int [16], int);
void editabuleiro(char [16][16], int);

int main(){
    char tabuleiro[16][16];
    int eixonum[16];
    char eixoletras[16];
    int n, scan;
    printf("Introduza o numero de linhas e colunas, este numero deve ser impar e estar entre 7 e 15:\n");
    scanf("%d", &n);
    while(n<7 || n>15 || (n%2)==0){
        printf("Nao introduzio um valor valido, introduza um valor impar entre 7 e 15: ");
        scanf("%d ", &n);
    }
    initablueiro(tabuleiro, eixoletras, eixonum, n);
    printabuleiro(tabuleiro, eixoletras, eixonum, n);
    editabuleiro(tabuleiro, n);
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
}

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

void editabuleiro(char tabuleiro[16][16], int n){
    int i=3, k, x, x2=0, y, dir, len, len_palavra, count=-1, multi=1, tempx, tempy;
    char input[25];
    scanf("%s", input);
    len=strlen(input);
    len_palavra=len-3;
    x=input[1]-'0';
    y=input[0]-'@';
    if(y>26){
        y=input[0]-'`';
    }
    dir=input[2]-'@';
    if(dir<0){
        x2=(input[2]-'0')*10;
        x=x+x2;
        dir=input[3]-'@';
        len_palavra=len-4;
        i=4;
    }
    tempy=y;
    tempx=x;
    if(dir==8 || dir==40){
        if(len_palavra>n-y){
            printf("Introduzio uma palavra demasiado grande.");
        }else{
            while(y<=n,i<=len){
                if((((y==(n/2))||y==((n/2)+2))&&(x==2 || x==n-1))||(((x==(n/2))||x==((n/2)+2))&&(y==2 || y==n-1))){
                    printf("Esta palavra usa um espaco proibido!\n");
                    while(y>=tempy){
                        tabuleiro[x][y]='.';
                        if((((y==(n/2))||y==((n/2)+2))&&(x==2 || x==n-1))||(((x==(n/2))||x==((n/2)+2))&&(y==2 || y==n-1))){
                            tabuleiro[x][y]='#';
                        }
                        y--;
                    }
                    break;
                }
                tabuleiro[x][y]=input[i];
                if(x==1 && y==1 || x==1 && y==n || x==n && y==1 || x==n && y==n){
                    multi++;
                }else if(i==k || n-i==k-1){
                    count++;
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    count+=2;
                }
                count++;
                y++, i++;
            }
        }
    }else if(dir==22 || dir==54){
        if(len_palavra>n-x){
            printf("Introduzio uma palavra demasiado grande.");
        }else{
            while(x<=n,i<=len_palavra){
                if((((y==(n/2))||y==((n/2)+2))&&(x==2 || x==n-1))||(((x==(n/2))||x==((n/2)+2))&&(y==2 || y==n-1))){
                    printf("Esta palavra usa um espaco proibido!\n");
                    while(x>=tempx){
                        tabuleiro[x][y]='.';
                        if((((y==(n/2))||y==((n/2)+2))&&(x==2 || x==n-1))||(((x==(n/2))||x==((n/2)+2))&&(y==2 || y==n-1))){
                            tabuleiro[x][y]='#';
                        }
                        x--;
                    }
                    break;
                }
                tabuleiro[x][y]=input[i];
                if(x==1 && y==1 || x==1 && y==n || x==n && y==1 || x==n && y==n){
                    multi++;
                }else if(i==k || n-i==k-1){
                    count++;
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    count+=2;
                }
                count++;
                x++, i++;
            }
        }
    }
    count*=multi;
    printf("Essa jogada valeu %d pontos!", count);
}
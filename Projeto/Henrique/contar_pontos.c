#include "Projeto_Final.h"

int contar_pontos (char palavra[16], char *tabuleiro[16], int x, int y , int dir, int n, char coordenadas[5])
{
    int count = 0, multi = 1, len = 0, i = 0, x2 = 0;
    if(coordenadas != 0)
    {
        x=coordenadas[1]-'0';
        y=coordenadas[0]-'@';
        if(y>26){
            y=coordenadas[0]-'`';
        }
        dir=coordenadas[2]-'@';
        if(dir<0){
            x2=coordenadas[2]-'0';
            x=(x*10)+x2;
            dir=coordenadas[3]-'@';
        }
    }
    len = strlen(palavra) - 1;
    while(i <= len)
    {
        switch(palavra[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'l':
            case 'n':
            case 'o':
            case 'r':
            case 's':
            case 't':
            case 'u':
                if(tabuleiro[x][y]==palavra[i]){
                    count++;
                }else if((x==1 && y==1) || (x==1 && y==n) || (x==n && y==1) || (x==n && y==n)){
                    count++;
                    multi++;
                }else if(x==y || n-x==y-1){
                    count+=2;
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    count+=3;
                }else{
                    count++;
                }
                break;
            case 'd':
            case 'g':
                if(tabuleiro[x][y]==palavra[i]){
                    count+=2;
                }else if((x==1 && y==1) || (x==1 && y==n) || (x==n && y==1) || (x==n && y==n)){
                    count+=2;
                    multi++;
                }else if(x==y || n-x==y-1){
                    count+=4;
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    count+=6;
                }else{
                    count+=2;
                }
                break;
            case 'b':
            case 'c':
            case 'm':
            case 'p':
                if(tabuleiro[x][y]==palavra[i]){
                    count+=3;
                }else if((x==1 && y==1) || (x==1 && y==n) || (x==n && y==1) || (x==n && y==n)){
                    count+=3;
                    multi++;
                }else if(x==y || n-x==y-1){
                    count+=6;
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    count+=9;
                }else{
                    count+=3;
                }
                break;
            case 'f':
            case 'h':
            case 'v':
            case 'w':
            case 'y':
                if(tabuleiro[x][y]==palavra[i]){
                    count+=4;
                }else if((x==1 && y==1) || (x==1 && y==n) || (x==n && y==1) || (x==n && y==n)){
                    count+=4;
                    multi++;
                }else if(x==y || n-x==y-1){
                    count+=8;
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    count+=12;
                }else{
                    count+=4;
                }
                break;
            case 'k':
                if(tabuleiro[x][y]==palavra[i]){
                    count+=5;
                }else if((x==1 && y==1) || (x==1 && y==n) || (x==n && y==1) || (x==n && y==n)){
                    count+=5;
                    multi++;
                }else if(x==y || n-x==y-1){
                    count+=10;
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    count+=15;
                }else{
                    count+=5;
                }
                break;
            case 'j':
            case 'x':
                if(tabuleiro[x][y]==palavra[i]){
                    count+=8;
                }else if((x==1 && y==1) || (x==1 && y==n) || (x==n && y==1) || (x==n && y==n)){
                    count+=8;
                    multi++;
                }else if(x==y || n-x==y-1){
                    count+=16;
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    count+=24;
                }else{
                    count+=8;
                }
                break;
            case 'q':
            case 'z':
                if(tabuleiro[x][y]==palavra[i]){
                    count+=10;
                }else if((x==1 && y==1) || (x==1 && y==n) || (x==n && y==1) || (x==n && y==n)){
                    count+=10;
                    multi++;
                }else if(x==y || n-x==y-1){
                    count+=20;
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    count+=30;
                }else{
                    count+=10;
                }
                break;
        }
        if(dir == 8 || dir == 40)
        {
            y++;
        }else if(dir == 22 || dir == 54)
        {
            x++;
        }
        i++;
    }
    count *= multi;
    return count;
}

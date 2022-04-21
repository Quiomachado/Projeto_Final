#include "Projeto_Final.h"

int ver_palavra (char coordenadas[5], char palavra[16], int n, char *tabuleiro[16], int x, int y, int dir, int jogada)
{
    int i=0, x2=0, len=0, len_palavra=0, tempx=0, tempy=0, flag = 0;
    char temptabuleiro[20];
    len=strlen(palavra) - 1;
    flag = len;
    len_palavra=len;
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
    if(x>n || y>n){
        //printf("Introduziu coordenadas que nao pertencem!\n");
        return 1;
    }
    tempy=y;
    tempx=x;
    if(dir ==8 || dir == 40){
        if(len_palavra>n-y){
            //printf("Introduziu uma palavra demasiado grande.\n");
            return 1;
        }else{
            while(y<=n && i<=len){
                temptabuleiro[y]=tabuleiro[x][y];
                if((((y==(n/2))||y==((n/2)+2))&&(x==2 || x==n-1))||(((x==(n/2))||x==((n/2)+2))&&(y==2 || y==n-1))){
                    //printf("Esta palavra usa um espaco proibido!\n");
                    while(y>=tempy){
                        tabuleiro[x][y]=temptabuleiro[y];
                        y--;
                    }
                    return 1;
                }
                if(tabuleiro[x][y]!='.' && tabuleiro[x][y]!='$' && tabuleiro[x][y]!='2' && tabuleiro[x][y]!='3' && tabuleiro[x][y]!=palavra[i]){
                    //printf("A sua palavra nao utiliza um carater ja colocado anteriormente!\n");
                    return 1;
                }
                if(jogada != 1 && (tabuleiro[x][y]=='.' || tabuleiro[x][y]=='$' || tabuleiro[x][y]=='2' || tabuleiro[x][y]=='3'))
                {
                    flag--;
                }
                y++, i++;
            }
        }
        if(jogada != 1 && flag != 0)
        {
            //printf("A sua palavra nao utiliza uma palavra ja introduzida.\n");
            return 1;
        }
    }else if(dir==22 || dir==54){
        if(len_palavra>n-x){
            //printf("Introduzio uma palavra demasiado grande.\n");
            return 1;
        }else{
            while(x<=n && i<=len){
                temptabuleiro[x]=tabuleiro[x][y];
                if((((y==(n/2))||y==((n/2)+2))&&(x==2 || x==n-1))||(((x==(n/2))||x==((n/2)+2))&&(y==2 || y==n-1))){
                    //printf("Esta palavra usa um espaco proibido!\n");
                    while(x>=tempx){
                        tabuleiro[x][y]=temptabuleiro[x];
                        x--;
                    }
                    return 1;
                }
                if(tabuleiro[x][y]!='.' && tabuleiro[x][y]!='$' && tabuleiro[x][y]!='2' && tabuleiro[x][y]!='3' && tabuleiro[x][y]!=palavra[i]){
                    //printf("A sua palavra nao utiliza um carater ja colocado anteriormente!\n");
                    return 1;
                }
                if(jogada != 1 && (tabuleiro[x][y]=='.' || tabuleiro[x][y]=='$' || tabuleiro[x][y]=='2' || tabuleiro[x][y]=='3'))
                {
                    flag--;
                }
                x++, i++;
            }
        }
        if(jogada != 1 && flag != 0)
        {
            //printf("A sua palavra nao utiliza uma palavra ja introduzida.\n");
            return 1;
        }
    }
    return 0;
}

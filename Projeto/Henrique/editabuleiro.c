#include "Projeto_Final.h"

void editabuleiro(char *tabuleiro[16], char coordenadas[5], char palavra[16], int n, int x, int y, int dir)
{
    int x2 = 0, i = 0, len;
    len = strlen(palavra) - 1;
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
    if(dir == 8 || dir == 40)
    {
        while(y <= n && i <= len)
        {
            tabuleiro[x][y] = palavra[i];
            y++, i++;
        }
    }else if(dir == 22 || dir == 54)
    {
        while(x <= n && i <= len)
        {
            tabuleiro[x][y] = palavra[i];
            x++, i++;
        }
    }
}

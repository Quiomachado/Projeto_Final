#include "Projeto_Final.h"

void alg_cpu(char *tabuleiro[16], int num_linhas, char *dicionario[140], int linhas, char palavra)
{
    int jogada = 1, x = 0, y = 0, i = 0;
    char num, letra, direcao;
    if(jogada == 1)
    {
        y = (num_linhas/2) + 1;
        letra = y + '@';
        direcao = 'h';
        for(i = 0; i <= linhas; i++)
        {
            palavra = dicionario[i];
        }
    }
}

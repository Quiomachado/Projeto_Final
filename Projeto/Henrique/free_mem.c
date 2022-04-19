#include "Projeto_Final.h"

void free_mem(int num_linhas, char *tabuleiro[16], char *dicionario_org[140], int linhas)
{
    int i = 0;
    for(i = 0;i<=num_linhas;i++)
    {
        free(tabuleiro[i]);
    }
    for(i = 0;i<=linhas;i++)
    {
        free(dicionario_org[i]);
    }
}

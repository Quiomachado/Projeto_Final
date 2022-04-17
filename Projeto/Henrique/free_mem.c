#include "Projeto_Final.h"

void free_mem(int num_linhas, char *tabuleiro[16])
{
    int i = 0;
    for(i = 1;i<=num_linhas;i++)
    {
        free(tabuleiro[i]);
    }
}

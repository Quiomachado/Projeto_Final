#include "Projeto_Final.h"

void get_tabuleiro(char *tabuleiro[16], char *use_tabuleiro, int num_linhas)
{
    char buffer[MAX_SIZE];
    num_linhas = 0;
    FILE * tabu;
    if((tabu = fopen(use_tabuleiro, "r")) == NULL)
    {
        printf("Não foi possivel abrir o ficheiro com o tabuleiro.");
        return;
    }
    while(fgets(buffer, MAX_SIZE, tabu) != NULL)
    {
        tabuleiro[num_linhas] = (char *) calloc(MAX_SIZE, sizeof(char));
        strcpy(tabuleiro[num_linhas], buffer);
        num_linhas++;
    }
    fclose(tabu);
}

#include "Projeto_Final.h"

int get_dicionario (char *use_dicionario, char *dicionario[140], int num_linhas, int *linhas)
{
    int k = 0;
    char buffer[MAX_SIZE];
    FILE * dic;
    if((dic = fopen(use_dicionario, "r")) == NULL)
    {
        printf("Nao foi possivel abrir o ficheiro de dicionario.\n");
        return 1;
    }
    while(fgets(buffer, MAX_SIZE, dic) != NULL)
    {
        if(strlen(buffer) <= num_linhas + 1)
        {
            dicionario[k] = (char *) calloc(MAX_SIZE + 1, sizeof(char));
            strcpy(dicionario[k], buffer);
            k++;
        }
    }
    *linhas = k - 1;
    fclose(dic);
    return 0;
}

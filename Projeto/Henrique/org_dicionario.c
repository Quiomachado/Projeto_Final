#include "Projeto_Final.h"

int org_dicionario (char *dicionario, char *dicionario_org[140], int num_linhas, int *linhas)
{
    int i = 0, flag = 0, k = 0;
    char buffer;
    FILE * dic;
    if((dic = fopen(dicionario, "r")) == NULL)
    {
        printf("Nao foi possivel abrir o ficheiro de dicionario.\n");
        return 1;
    }
    dicionario_org[i] = (char *) calloc(MAX_SIZE, sizeof(char));
    while((buffer = fgetc(dic)) != EOF)
    {
        if(buffer < 'a' || buffer > 'z')
        {
            flag++;
        }
        if(buffer == '\n')
        {
            if(k < 2 || k > num_linhas + 1 || flag != 0)
            {
                dicionario_org[i] = 0;
                i--;
            }
            i++;
            k = 0;
            flag = 0;
            dicionario_org[i] = (char *) calloc(MAX_SIZE, sizeof(char));
            continue;
        }
        if(flag == 0)
        {
            dicionario_org[i][k] = buffer;
            k++;
        }
        if(flag != 0)
        {
            dicionario_org[i] = 0;
            continue;
        }
    }
    *linhas = i;
    return 0;
}

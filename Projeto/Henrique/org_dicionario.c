#include "Projeto_Final.h"

int org_dicionario(char *dicionario_org[140], char *dicionario[140], int *linhas, int num_linhas)
{
    int i = 0, k = 0, n = 0, flag = 0, j = 0, s = 0;
    char *buffer[140] = {NULL};
    for(i = num_linhas + 1;i >= 2; i--)
    {
        for(k = 0;k <= *linhas; k++)
        {
            if(i == strlen(dicionario[k]))
            {
                buffer[n] = (char *) calloc(i + 2, sizeof(char));
                strcpy(buffer[n], dicionario[k]);
                n++;
            }
        }
    }
    for(i = 0;i < n; i++)
    {
        flag = 0;
        for(k = 0;k <= num_linhas; k++)
        {
            if(buffer[i][k] == '\n' && flag == 0)
            {
                dicionario_org[j] = (char*) calloc(k + 1, sizeof(char));
                for(s = 0; s < k; s++)
                {
                    dicionario_org[j][s] = buffer[i][s];
                }
                j++;
                continue;
            }
            if(buffer[i][k] < 'a' || buffer[i][k] > 'z')
            {
                flag++;
            }
        }
    }
    for(i = 0; i <= *linhas; i++)
    {
        free(dicionario[i]);
    }
    for(i = 0; i <= n; i++)
    {
        free(buffer[i]);
    }
    *linhas = j - 1;
    return 0;
}

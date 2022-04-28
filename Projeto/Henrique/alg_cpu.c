#include "Projeto_Final.h"

int alg_cpu(char *tabuleiro[16], int num_linhas, char *dicionario_org[140], int linhas, char palavra[16], int jogada, int *pontos_finais, int max_jogadas, char *registar_alg)
{
    if(jogada == max_jogadas)
        return 1;
    if(jogada == 0)
        return 1;
    int x = 0, y = 0, i = 0, dir = 8, tamanho = 0, num_posicoes = 0, k = 0, pontos = 0, max_pontos = 0, max_index = 1, x_final = 0, y_final = 0, dir_final = 0, j = 0;
    if(registar_alg != NULL)
    {
        FILE *registo;
        if((registo = fopen(registar_alg, "a")) == NULL)
        {
            printf("Não foi possivel criar o ficheiro de registo.\n");
            return 1;
        }
        fprintf(registo, "\n\nJogada numero %d:\n\n", jogada);
        fclose(registo);
    }
    if(jogada == 1)
    {
        x = (num_linhas/2) + 1;
        dir = 8;
        for(i = 0; i <= linhas; i++)
        {
            tamanho = strlen(dicionario_org[i]);
            if(tamanho > (num_linhas / 2))
            {
                num_posicoes = num_linhas - tamanho + 1;
                for(k = 1;k <= num_posicoes; k++)
                {
                    y = k;
                    if(ver_palavra(0, dicionario_org[i], num_linhas, tabuleiro, x, y, dir, jogada) == 0)
                    {
                        pontos = contar_pontos(dicionario_org[i], tabuleiro, x, y, dir, num_linhas, 0);
                        if(registar_alg != NULL)
                        {
                            FILE *registo;
                            if((registo = fopen(registar_alg, "a")) == NULL)
                            {
                                printf("Não foi possivel criar o ficheiro de registo.\n");
                                return 1;
                            }
                            fprintf(registo, "%c%d%c %s %d pontos.\n", y + '@', x, dir + '@', dicionario_org[i], pontos);
                            fclose(registo);
                        }
                        if(pontos > max_pontos)
                        {
                            max_pontos = pontos;
                            max_index = i;
                            x_final = x;
                            y_final = y;
                            dir_final = 8;
                        }
                    }
                }
            }else if(tamanho <= (num_linhas / 2))
            {
                num_posicoes = tamanho;
                for(k = num_posicoes;k >= 1; k--)
                {
                    y =(((num_linhas / 2) + 1) - k) + 1;
                    if(ver_palavra(0, dicionario_org[i], num_linhas, tabuleiro, x, y, dir, jogada) == 0)
                    {
                        pontos = contar_pontos(dicionario_org[i], tabuleiro, x, y, dir, num_linhas, 0);
                        if(registar_alg != NULL)
                        {
                            FILE *registo;
                            if((registo = fopen(registar_alg, "a")) == NULL)
                            {
                                printf("Não foi possivel criar o ficheiro de registo.\n");
                                return 1;
                            }
                            fprintf(registo, "%c%d%c %s %d pontos.\n", y + '@', x, dir + '@', dicionario_org[i], pontos);
                            fclose(registo);
                        }
                        if(pontos > max_pontos)
                        {
                            max_pontos = pontos;
                            max_index = i;
                            x_final = x;
                            y_final = y;
                            dir_final = 8;
                        }
                    }
                }
            }
        }
    }else
    {
        for(j = 0;j <= 1; j++)
        {
            if(j == 0)
            {
                dir = 22;
                for(y = 1;y <= num_linhas;y++)
                {
                    for(x = 1;x <= num_linhas - 1;x++)
                    {
                        for(i = 0; i <= linhas; i++)
                        {
                            if(ver_palavra(0, dicionario_org[i], num_linhas, tabuleiro, x, y, dir, jogada) == 0)
                            {
                                pontos = contar_pontos(dicionario_org[i], tabuleiro, x, y, dir, num_linhas, 0);
                                if(registar_alg != NULL)
                                {
                                    FILE *registo;
                                    if((registo = fopen(registar_alg, "a")) == NULL)
                                    {
                                        printf("Não foi possivel criar o ficheiro de registo.\n");
                                        return 1;
                                    }
                                    fprintf(registo, "%c%d%c %s %d pontos.\n", y + '@', x, dir + '@', dicionario_org[i], pontos);
                                    fclose(registo);
                                }
                                if(pontos > max_pontos)
                                {
                                    max_pontos = pontos;
                                    max_index = i;
                                    x_final = x;
                                    y_final = y;
                                    dir_final = dir;
                                }
                            }
                        }
                    }
                }
            }else if(j == 1)
            {
                dir = 8;
                for(x = 1;x <= num_linhas;x++)
                {
                    for(y = 1;y <= num_linhas - 1;y++)
                    {
                        for(i = 0; i <= linhas; i++)
                        {
                            if(ver_palavra(0, dicionario_org[i], num_linhas, tabuleiro, x, y, dir, jogada) == 0)
                            {
                                pontos = contar_pontos(dicionario_org[i], tabuleiro, x, y, dir, num_linhas, 0);
                                if(registar_alg != NULL)
                                {
                                    FILE *registo;
                                    if((registo = fopen(registar_alg, "a")) == NULL)
                                    {
                                        printf("Não foi possivel criar o ficheiro de registo.\n");
                                        return 1;
                                    }
                                    fprintf(registo, "%c%d%c %s %d pontos.\n", y + '@', x, dir + '@', dicionario_org[i], pontos);
                                    fclose(registo);
                                }
                                if(pontos > max_pontos)
                                {
                                    max_pontos = pontos;
                                    max_index = i;
                                    x_final = x;
                                    y_final = y;
                                    dir_final = dir;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(max_pontos == 0)
        return 1;
    editabuleiro(tabuleiro, 0, dicionario_org[max_index], num_linhas, x_final, y_final, dir_final);
    printf("\n%c%d%c %s %d pontos!\n",y_final + '@', x_final, dir_final + '@', dicionario_org[max_index], max_pontos);
    *pontos_finais = max_pontos;
    return 0;
}

#include "Projeto_Final.h"

int main(int argc, char *argv[])
{
    char *tabuleiro[16] = {NULL}, eixoletras[16]={0}, input[25]={0}, *use_dicionario = "/usr/share/dict/words", *letras = "letras.txt", *use_tabuleiro = NULL, *escrever = NULL, *registar_alg = NULL, *dicionario_org[140]={NULL}, coordenadas[5], palavra[16], *dicionario[140] = {NULL};
    int eixonum[16]={0}, num_linhas = 9, n_letras = 0, max_jogadas = -1, modo = 1, linhas = 0, flag = 0, pontos = 0, pontos_totais = 0, jogada = 1;
    if(get_comando(argc, argv, &num_linhas, &use_dicionario, &letras, &n_letras, &max_jogadas, &use_tabuleiro, &modo, &escrever, &registar_alg) == 1)
    {
        return EXIT_FAILURE;
    }
    if(use_tabuleiro != NULL)
    {
        if(get_tabuleiro(tabuleiro, use_tabuleiro, &num_linhas, eixoletras, eixonum, &jogada) == 1)
        {
            return 1;
        }
    }else
    {
        initablueiro(tabuleiro, eixoletras, eixonum, num_linhas);
    }
    get_dicionario(use_dicionario, dicionario, num_linhas, &linhas);
    org_dicionario(dicionario_org, dicionario, &linhas, num_linhas);
    max_jogadas += jogada;
    if(modo == 1)
    {
        do
        {
            printabuleiro(tabuleiro, eixoletras, eixonum, num_linhas);
            printf("Introduza as coordenadas, seguida da orientacao e da palavra: ");
            fgets(input, 25, stdin);
            if((input[0]=='f' && input[1]=='i' && input[2]=='m')||(input[0]=='F' && input[1]=='I' && input[2]=='M'))
            {
                continue;
            }
            strcpy(coordenadas, strtok(input, " "));
            strcpy(palavra, strtok(NULL, "\n"));
            if((flag = ver_palavra(coordenadas, palavra, num_linhas, tabuleiro, 0, 0, 0, jogada)) == 0)
            {
                pontos = contar_pontos(palavra, tabuleiro, 0, 0, 0, num_linhas, coordenadas);
                editabuleiro(tabuleiro, coordenadas, palavra, num_linhas, 0, 0, 0);
                pontos_totais += pontos;
                printf("\n%s %s %d pontos nesta jogada\n", coordenadas, palavra, pontos);
            }else if(flag == 1)
            {
                continue;
            }
            jogada++;
        }while((input[0]!='f' && input[1]!='i' && input[2]!='m')&&(input[0]!='F' && input[1]!='I' && input[2]!='M'));
        printf("\nPontos Totais: %d\n", pontos_totais);
        free_mem(num_linhas, tabuleiro, dicionario_org, linhas);
        return 0;
    }else
    {
        while(alg_cpu(tabuleiro, num_linhas, dicionario_org, linhas, palavra, jogada, &pontos, max_jogadas, registar_alg) == 0)
        {
            pontos_totais += pontos;
            printabuleiro(tabuleiro, eixoletras, eixonum, num_linhas);
            jogada ++;
        }
        if(max_jogadas == jogada && escrever != NULL)
        {
            print_file(tabuleiro, escrever, num_linhas, eixoletras, eixonum);
        }
        printf("\nTabuleiro Final: \n");
        printabuleiro(tabuleiro, eixoletras, eixonum, num_linhas);
        printf("\nPontos Totais: %d\n", pontos_totais);
        free_mem(num_linhas, tabuleiro, dicionario_org, linhas);
    }
    return 0;
}

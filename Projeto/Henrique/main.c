#include "Projeto_Final.h"

int main(int argc, char *argv[])
{
    char *tabuleiro[16] = {NULL}, eixoletras[16]={0}, input[25]={0}, *use_dicionario = "/usr/share/dict/words", *letras = "letras.txt", *use_tabuleiro = NULL, *escrever = NULL, *registar_alg = NULL, *dicionario_org[140]={NULL}, coordenadas[5], palavra[16], *dicionario[140] = {NULL};
    int eixonum[16]={0}, num_linhas = 9, n_letras = 0, max_jogadas = -1, modo = 1, linhas = 0;
    if(get_comando(argc, argv, &num_linhas, &use_dicionario, &letras, &n_letras, &max_jogadas, &use_tabuleiro, &modo, &escrever, &registar_alg) == 1)
    {
        return EXIT_FAILURE;
    }
    if(use_tabuleiro != NULL)
    {
        if(get_tabuleiro(tabuleiro, use_tabuleiro, &num_linhas, eixoletras, eixonum) == 1)
        {
            return 1;
        }
    }else
    {
        initablueiro(tabuleiro, eixoletras, eixonum, num_linhas);
    }
    get_dicionario(use_dicionario, dicionario, num_linhas, &linhas);
    org_dicionario(dicionario_org, dicionario, linhas, num_linhas);
    do
    {
        editabuleiro(tabuleiro, coordenadas, palavra, num_linhas);
        printabuleiro(tabuleiro, eixoletras, eixonum, num_linhas);
        printf("Introduza as coordenadas, seguida da orientacao e da palavra: ");
        fgets(input, 25, stdin);
        if((input[0]=='f' && input[1]=='i' && input[2]=='m')||(input[0]=='F' && input[1]=='I' && input[2]=='M'))
        {
            continue;
        }
        strcpy(coordenadas, strtok(input, " "));
        strcpy(palavra, strtok(NULL, "\n"));
    }while((input[0]!='f' && input[1]!='i' && input[2]!='m')&&(input[0]!='F' && input[1]!='I' && input[2]!='M'));
    free_mem(num_linhas, tabuleiro, dicionario_org, linhas);
    return 0;
}

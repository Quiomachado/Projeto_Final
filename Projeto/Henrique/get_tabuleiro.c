#include "Projeto_Final.h"

int get_tabuleiro(char *tabuleiro[16], char *use_tabuleiro, int *num_linhas, char eixoletras[16], int eixonum[16], int *jogada)
{
    int i=1, k=1, flag=1, meio = 0;
    char buffer;
    FILE * tabu;
    if((tabu = fopen(use_tabuleiro, "r")) == NULL)
    {
        printf("Não foi possivel abrir o ficheiro com o tabuleiro.");
        return 1;
    }
    tabuleiro[i] = (char *) calloc(MAX_SIZE, sizeof(char));//alocar memoria à primeira linha do tabuleiro
    while((buffer = fgetc(tabu)) != EOF)//ler o ficheiro carater a carater
    {
        if(flag==1 && buffer != ' ')//ignorar o eixo dos numeros atraves de uma flag
        {
            flag = 0;
            continue;
        }
        if(buffer >= 'A' && buffer <= 'Z')//ignorar eixo das letras
        {
            break;
        }
        if(buffer == '\n')
        {
            i++;
            k=1;//reset ao k
            flag ++; //indica que mudamos de linha para depois se ignorar o primeiro carater
            tabuleiro[i] = (char *) calloc(MAX_SIZE, sizeof(char)); //aloca memoria para a proxima linha do tabuleiro
            continue;
        }else if(buffer != ' ')
        {
            tabuleiro[i][k]=buffer;
            k++;
        }
    }
    tabuleiro[i] = 0;//apagar a ultima linha
    *num_linhas = i-1; //remover a linha das letras
    fclose(tabu);
    for(i=0;i<=*num_linhas;i++)//cria os eixos
    {
        eixonum[i]=i;
        eixoletras[i]=i+'@'; //Alterar o int para letras
    }
    meio = (*num_linhas/2) + 1;
    if(tabuleiro[meio][meio] <= 'z' && tabuleiro[meio][meio] >= 'a')
    {
        *jogada = 2;
    }
    return 0;
}


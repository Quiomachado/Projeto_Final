#include "Projeto_Final.h"

int main(int argc, char *argv[])
{
    char tabuleiro[16][16], eixoletras[16], input[25], *t=NULL, *d=NULL, *l=NULL, *m=NULL, *n=NULL, *i=NULL, *j=NULL, *o=NULL, *r=NULL;
    int eixonum[16], num_linhas;
    if(get_comando(argc, argv, t, d, l, m, n, i, j, o, r) == 1)
    {
        return 0;
    }
    do
    {
        printf("Introduza o numero de linhas e colunas, este numero deve ser IMPAR e estar entre 7 e 15:\n");
        scanf("%d", &num_linhas);
    }while((num_linhas<7)|| (num_linhas>15) || (num_linhas%2)==0);
    initablueiro(tabuleiro, eixoletras, eixonum, num_linhas);
    fgets(input, 25, stdin); //descartar a mudança de linha do scanf
    do
    {
        editabuleiro(tabuleiro, input, num_linhas);
        printabuleiro(tabuleiro, eixoletras, eixonum, num_linhas);
        printf("Introduza as coordenadas, seguida da orientacao e da palavra: ");
        fgets(input, 25, stdin);
    }while((input[0]!='f' && input[1]!='i' && input[2]!='m')&&(input[0]!='F' && input[1]!='I' && input[2]!='M'));
}

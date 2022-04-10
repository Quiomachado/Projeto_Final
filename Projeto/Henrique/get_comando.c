#include "Projeto_Final.h"

int get_comando(int argc, char *argv[], char *t, char *d, char *l, char *m, char *n, char *i, char *j, char *o, char *r)
{
    for(int k=1; k<=argc; k++)//loop que verifica as linhas de comando, começa em 1 porque argv[0] é o nome do ficheiro
    {
        if(strcmp(argv[k], "-h")==0)//verifica se o utilizador introduz a opcao de comando -h
        {
            printf("-h           ajuda para o utilizador\n");
            printf("-t lxc       dimensões do tabuleiro (linha x coluna).\n");
            printf("-d filename  nome do ficheiro de dicionário a utilizar\n");
            printf("-l filename  nome do ficheiro com letras a usar nas jogadas\n");
            printf("-m 5-20      número de letras que um jogador pode ter na sua mão para jogar\n");
            printf("-n nn        número de jogadas máximo a realizar\n");
            printf("-i filename  define ficheiro com o tabuleiro a usar em alternativa a jogar num tabuleiro vazio\n");
            printf("-j 1-4       modo de jogo 1 a 4\n");
            printf("-o filename  define ficheiro onde escrever o tabuleiro final.\n");
            printf("-r filename  define ficheiro para registo de todas as jogadas possíveis.\n");
            return 1;
        }
        if(strcmp(argv[k], "-t")==0)
        {
            strcpy(t, argv[k+1]);
        }else if(strcmp(argv[k], "-d")==0)
        {
            strcpy(d, argv[k+1]);
        }else if(strcmp(argv[k], "-l")==0)
        {
            strcpy(l, argv[k+1]);
        }else if(strcmp(argv[k], "-m")==0)
        {
            strcpy(m, argv[k+1]);
        }else if(strcmp(argv[k], "-n")==0)
        {
            strcpy(n, argv[k+1]);
        }else if(strcmp(argv[k], "-i")==0)
        {
            strcpy(i, argv[k+1]);
        }else if(strcmp(argv[k], "-j")==0)
        {
            strcpy(j, argv[k+1]);
        }else if(strcmp(argv[k], "-o")==0)
        {
            strcpy(o, argv[k+1]);
        }else if(strcmp(argv[k], "-r")==0)
        {
            strcpy(r, argv[k+1]);
        }
    }
    return 0;
}

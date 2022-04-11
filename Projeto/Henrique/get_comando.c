#include "Projeto_Final.h"

int get_comando(int argc, char *argv[], int num_linhas, char *dicionario)// char *t, char *d, char *l, char *m, char *n, char *i, char *j, char *o, char *r)
{
    int opt;
    while((opt=getopt(argc, argv, "ht:d:l:m:n:i:j:o:r:"))!=-1)
    {
        switch (opt)
        {
            case 'h':
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

            case 't':
                if((optarg[0] != optarg[2]) || ((optarg[0] -'0') < 7) || ((optarg[0] - '0') > 15) || (((optarg[0] - '0') % 2) == 0))
                {
                    printf("Nao introduziu um valor valido para a dimensao.");
                    return 1;
                }
                num_linhas=optarg[0];
                break;
            case 'd':
                dicionario=optarg;
                break;
        }
    }
    return 0;
}

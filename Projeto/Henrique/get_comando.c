#include "Projeto_Final.h"

int get_comando(int argc, char *argv[], int *num_linhas, char **use_dicionario, char **letras, int *n_letras, int *max_jogadas, char **use_tabuleiro, int *modo, char **escrever, char **registar_alg)
{
    int opt, linhas, colunas;
    while((opt=getopt(argc, argv, ":ht:d:l:m:n:i:j:o:r:"))!=-1)
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
                if(optarg[1]>='0' && optarg[1]<='9' && optarg[4]>='0' && optarg[4]<='9')
                {
                    linhas = ((optarg[0] - '0')*10)+(optarg[1] - '0');
                    colunas = ((optarg[3] - '0')*10)+(optarg[4] - '0');
                }else if(optarg[1]>='0' && optarg[1]<='9' && optarg[4]=='\0')
                {
                    linhas = ((optarg[0] - '0')*10)+(optarg[1] - '0');
                    colunas = optarg[3] - '0';
                }else if(optarg[1]== 'x' && optarg[3]<='9' && optarg[3]>='0')
                {
                    linhas = optarg[0] - '0';
                    colunas = ((optarg[3] - '0')*10)+(optarg[4] - '0');
                }else
                {
                    linhas = (optarg[0] - '0');
                    colunas = (optarg[2] - '0');
                }
                if((linhas != colunas) || (linhas < 7) || (linhas > 15) || ((linhas % 2) == 0))
                {
                    printf("Nao introduziu um valor valido para a dimensao.");
                    return 1;
                }
                *num_linhas = linhas;
                break;
            case 'd':
                *use_dicionario = optarg;
                break;
            case 'l':
                *letras = optarg;
                break;
            case 'm':
                *n_letras = optarg[0] -'0';
                if(optarg[1] != '\0')
                {
                   *n_letras = (*n_letras * 10) + (optarg[1] - '0');
                }
                if(*n_letras > 20 || *n_letras < 5)
                {
                    printf("Nao introduzio um valor valido para o numero de letras");
                    return 1;
                }
                break;
            case 'n':
                *max_jogadas = optarg[0] - '0';
                if(optarg[1] != '\0')
                {
                    *max_jogadas = (*max_jogadas * 10) + (optarg[1] - '0');
                    if(optarg[2] != '\0'){
                        *max_jogadas = (*max_jogadas * 10) + (optarg[2] - '0');
                    }
                }
                break;
            case 'i':
                *use_tabuleiro = optarg;
                break;
            case 'j':
                *modo = optarg[0] - '0';
                if(optarg[1] != '\0' || optarg[0] > 4 || optarg[0] < 0)
                {
                    printf("Nao introduzio um modo de jogo valido.");
                    return 1;
                }
                break;
            case 'o':
                *escrever = optarg;
                break;
            case 'r':
                *registar_alg = optarg;
                break;
            case ':':
                printf("Nao introduzio um parametro para o comando %c.", optopt);
                return 1;
        }
    }
    return 0;
}

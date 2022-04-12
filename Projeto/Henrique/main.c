#include "Projeto_Final.h"

int main(int argc, char *argv[])
{
    char tabuleiro[16][16], eixoletras[16], input[25], *dicionario = "/usr/share/dict/words", *letras = "letras.txt", *use_tabuleiro = NULL, *escrever = NULL, *registar_alg = NULL;
    int eixonum[16], num_linhas = 9, n_letras = 0, max_jogadas = -1, modo = 1;
    if(get_comando(argc, argv, &num_linhas, dicionario, letras, &n_letras, &max_jogadas, use_tabuleiro, &modo, escrever, registar_alg) == 1)
    {
        return EXIT_FAILURE;
    }
    initablueiro(tabuleiro, eixoletras, eixonum, num_linhas);
    do
    {
        editabuleiro(tabuleiro, input, num_linhas);
        printabuleiro(tabuleiro, eixoletras, eixonum, num_linhas);
        printf("Introduza as coordenadas, seguida da orientacao e da palavra: ");
        fgets(input, 25, stdin);
    }while((input[0]!='f' && input[1]!='i' && input[2]!='m')&&(input[0]!='F' && input[1]!='I' && input[2]!='M'));
    return 0;
}

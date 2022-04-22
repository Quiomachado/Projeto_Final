#include "Projeto_Final.h"

void print_file(char *tabuleiro[16], char *escrever, int n, char eixoletras[16], int eixonum[16])
{
    int i = 0, k = 0;
    FILE *ficheiro;
    if((ficheiro = fopen(escrever, "w")) == NULL)
    {
        printf("Não foi possivel escrever o tabuleiro final.");
        return;
    }
    for(i=1;i<=n;i++){
        if(i<=n){
            if(i<=9){
                fprintf(ficheiro, " %d ", eixonum[i]);
            }else{
                fprintf(ficheiro, "%d ", eixonum[i]);
            }
        }
        for(k=1;k<=n;k++){
            fprintf(ficheiro, "%c ", tabuleiro[i][k]);
        }
        fprintf(ficheiro, "\n");
    }
    for(i=n;i<=n;i++){
        fprintf(ficheiro, "   ");
        for(k=1;k<=n;k++){
            fprintf(ficheiro, "%c ", eixoletras[k]);
        }
    }
    fclose(ficheiro);
    return;
}

#include "Projeto_Final.h"

int main(){
    char tabuleiro[16][16];
    int eixonum[16];
    char eixoletras[16];
    int n;
    char input[25];
    printf("Introduza o numero de linhas e colunas, este numero deve ser IMPAR e estar entre 7 e 15:\n");
    scanf("%d", &n);
    while((n<7)|| (n>15) || (n%2)==0){
        printf("Nao introduziu um valor valido, introduza um valor IMPAR entre 7 e 15:\n");
        scanf("%d", &n);
    }
    initablueiro(tabuleiro, eixoletras, eixonum, n);
    printabuleiro(tabuleiro, eixoletras, eixonum, n);
    printf("Introduza as coordenadas, seguida da orientacao e da palavra: ");
    fgets(input, 25, stdin); //descartar a mudança de linha do scanf
    fgets(input, 25, stdin);
    while((input[0]!='f' && input[1]!='i' && input[2]!='m')&&(input[0]!='F' && input[1]!='I' && input[2]!='M')){
        editabuleiro(tabuleiro, input, n);
        printabuleiro(tabuleiro, eixoletras, eixonum, n);
        printf("Introduza as coordenadas, seguida da orientacao e da palavra: ");
        fgets(input, 25, stdin);
    }
}

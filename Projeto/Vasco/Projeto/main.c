#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tabuleiro [15][15], n, i, eixoY;
    /*
    definir as variaveis,
    dimensao da matriz,
    variavel n equivalente a dimensao da matriz,
    variavel i utilizada nos ciclos while,
    variavel eixoY para imprimir os valores da dimensao
    */
    double eixoXNum;
    char eixoXLetra;

    printf("Quantas linhas/colunas deseja para o seu tabuleiro:\n");
    scanf("%i", &n);

    while (n<7){
        printf("As dimensoes do tabuleiro precisam de ser numero IMPAR compreendido entre 7 e 15\nRepita o seu numero:\n");
        scanf("%i", &n);
    }
    while (n>15){
        printf("As dimensoes do tabuleiro precisam de ser numero IMPAR compreendido entre 7 e 15\nRepita o seu numero:\n");
        scanf("%i", &n);
    }
    while (n%2==0){
        printf("As dimensoes do tabuleiro precisam de ser numero IMPAR compreendido entre 7 e 15\nRepita o seu numero:\n");
        scanf("%i", &n);
    }
    /*
    Esta primeira parte foi so para definir o tamanho VALIDO da matriz
    Atraves de ciclos while ate obter uma dimensao valida
    */

    printf("\n\n\nAQUI ESTA O SEU TABULEIRO:\n\n");
    for(i=1; i<=n; i++){
        eixoY=i;
        printf("%i\n", eixoY);
    }
    printf(" ");
    for(i=1; i<=n; i++){
        eixoXNum=i+64;
        eixoXLetra=eixoXNum;
        printf("%c ", eixoXLetra);
    }


    return 0;
}

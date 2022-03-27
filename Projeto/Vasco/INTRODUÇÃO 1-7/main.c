#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//AULAS 1, 2, 3 LINGUAGEM C

int main()
{

    //AULAS 1, 2, 3 LINGUAGEM C


    //Fazer um comentario

    /*
    Fazer
    Um
    Comentario
    */

    /*
    -printf mostra o texto q escrevermos a seguir
    -"\n" irá fazer ENTER dps de mostrar a frase
    */

    printf("INTODUÇAO:\nMeu primeiro programa.\n\n");




    //AULA 4, 5, 6 LINGUAGEM C


    int minhaIdade; //Declarei variavel do tipo integer e de nome "minhaIdade"

    minhaIdade = 20; //Atribui o valor 23 à variável

    printf("4.\nMinha idade e' = %i.\n\n", minhaIdade); //Escrevi o texto = "%i q representa uma variavel q temos q meter dps do texto entre parentesis



    int maeIdade;
    maeIdade=40;

    int paiIdade=45; //Pode-se logo atribuir um valor a variavel

    printf("5.\nMinha idade e' = %i.\nPai idade e' = %i.\nMae idade e' = %i.\n\n", minhaIdade, paiIdade,maeIdade);//Declarar as variaveis pela ordem respetiva de aparecimento



    int irmaoIdade = 15;

    int idadeTotal;
    idadeTotal=minhaIdade+maeIdade+paiIdade+irmaoIdade; //Operacoes matematicas: + - * /

    printf("6.\nA idade total e' %i\n\n", idadeTotal);




    //AULA 7 LINGUAGEM C


    int base;
    int altura;
    int area;

    printf("7.\nDigite o valor da base:");
    scanf("%i", &base); //Vai ler o valor escrito e associar a uma das variaveis, neste caso a variavel base

    printf("\nDigite o valor da altura:");
    scanf("%i", &altura);//Mm coisa com a a variavel altura

    area=base*altura; //Definir q a variavel area e o produto de outras duas
    printf("\nO valor da area do retangulo e' = %i\n", area); //Apresentar o valor da area



    return 0;
}












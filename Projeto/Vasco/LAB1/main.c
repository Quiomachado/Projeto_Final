#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, aux;
    i=0;
    while(i < 3){
        scanf("%d", &n);
        aux = 2;
        while(n%aux !=0){
            aux = aux+1;
        }
        if(n != aux){
            printf("o numero %d nao e primo\n",n);
        }else{
            printf("o numero %d e primo\n", n);
        }
        i=i+1;
    }
    return 0;
}

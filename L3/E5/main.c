#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 1000

int SieveOfEratosthenes(int, int []);
void FlagMultipleNumbers (int n, int sq, int primos[]);

int main(){
    int n, sq;
    int primos[MAX_SIZE];
    printf("Introduza um numero inteiro positivo entre 1 e 1000: \n");
    scanf("%d", &n);
    if(n>=1 && n<=1000){
        sq = SieveOfEratosthenes(n, primos);
        FlagMultipleNumbers(n, sq, primos);
    }else
        printf("Nao introduziu um valor valido.");
    return EXIT_SUCCESS;
}

int SieveOfEratosthenes(int n, int primos[]){
    int i, sq;
    for(i=2; i<=n;i++){
        primos[i]=i;
    }
    sq = sqrt(n);
    return sq;
}

void FlagMultipleNumbers (int n, int sq, int primos[]){
    int i, j;
    for(i=2;i<=sq;i++){
        if(primos[i]!= 0){
            for(j=2;j<n;j++){
                if(primos[i]*j > n)
                    break;
                else
                    primos[primos[i]*j]=0;
            }
        }
    }
    for(i=2; i<=n; i++){
        if(primos[i]!=0)
            printf("%d\n",primos[i]);
    }
}
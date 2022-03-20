#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void SieveOfEratosthenes();

int main(){
    SieveOfEratosthenes();
}

void SieveOfEratosthenes(){
    int n,i, j;
    printf("Introduza um numero inteiro positivo entre 1 e 1000: \n");
    scanf("%d", &n);
    int primos[n];
    for(i=2; i<=n;i++){
        primos[i]=i;
    }
    i=2;
    while((i*i)<=n){
        if(primos[i]!= 0){
            for(j=2;j<n;j++){
                if(primos[i]*j > n)
                    break;
                else
                    primos[primos[i]*j]=0;
            }
        }
        i++;
    }
    for(i=2; i<=n; i++){
        if(primos[i]!=0)
            printf("%d\n",primos[i]);
    }
}
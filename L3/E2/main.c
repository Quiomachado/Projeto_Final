#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int x);
int comb(int x, int y);

int main()
{
   int i, k, n, space;
   printf("Introduza n: ");
   scanf("%d", &n);
   for(i=0;i<=n;i++, k=0){
       for(space=1; space <= n-i; ++space){
           printf(" ");
       }
       for(k=0;k<=i;k++)
       {
           printf("%d ", comb(i,k));
       }
       printf("\n");
   }
}

int factorial(int x)
{
    int i, num=1;
    for(i=1;i<=x;i++){
        num*=i;
    }
    return num;
}

int comb(int n, int k)
{
    int z;
    z=factorial(n)/(factorial(k)*factorial(n-k));
    return z;
}
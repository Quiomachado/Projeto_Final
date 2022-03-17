#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int x);
int comb(int x, int y);

int main()
{
   int i, k, n, space;
   k = 0;
   printf("Introduza n: ");
   scanf("%d", &n);
   for(i=1;i<=n;++i, k=0){
       for(space=1; space <= n-i; ++space){
           printf("  ");
       }
       while(k != 2 * i - 1){
           printf("%d ", comb(i,k));
            ++k;
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
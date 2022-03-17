#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
   int i, k, n, space;
   k = 0;
   printf("Introduza n: ");
   scanf("%d", &n);
   for(i=1;i<=n;++i, k=0){
       for(space=1; space <= n-i; ++space){
           printf("  ");
       }
       while(k != 2 * i - 1){
           printf("* ");
            ++k;
       }
       printf("\n");
   }
}
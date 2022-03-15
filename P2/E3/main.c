#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int i, k, n;
    printf("Insira a altura do triangulo: ");
    scanf("%d", &n);
    for(i=1;i<=n; i++) {
        for(k=1;k<=i; k++){
            printf("* ");
        }
        printf("\n");
    }
    for(i=n-1; i>=1; i--){
        for(k=1;k<=i; k++){
            printf("* ");
        }
        printf("\n");
    }    
    return 0;
}
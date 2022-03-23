#include <stdio.h>
#include <stdlib.h>

void load_mat(int, int, int [11][11], int);

int main(){
    int n, m;
    int mat1 [11][11];
    int mat2 [11][11];
    printf("Introduza n:\n");
    scanf("%d", &n);
    while(n>10){
        printf("O valor de n nao pode ser maior que 10, introduza n de novo:\n");
        scanf("%d", &n);
    }
    printf("Introduza m:\n");
    scanf("%d", &m);
    while(m>10){
        printf("O valor de m nao pode ser maior que 10, introduza m de novo:\n");
        scanf("%d", &m);
    }
    load_mat(n, m, mat1, 1);
    load_mat(n, m, mat2, 2);
}

void load_mat(int n, int m, int matriz[11][11], int e){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Introduza o valor da posicao %d %d na matriz%d:\n", i, j, e);
            scanf("%d", &matriz[i][j]);
        }
    }
    return;
}

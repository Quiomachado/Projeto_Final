#include <stdio.h>
#include <stdlib.h>

void load_mat(int, int, int [11][11], int);
void sum_mat(int , int , int [11][11], int [11][11]);
void print_mat(int , int , int [11][11]);

int main(){
    int n, m;
    int mat1 [11][11];
    int mat2 [11][11];
    printf("Introduza m:\n");
    scanf("%d", &m);
    while(m>10){
        printf("O valor de m nao pode ser maior que 10, introduza m de novo:\n");
        scanf("%d", &m);
    }
    printf("Introduza n:\n");
    scanf("%d", &n);
    while(n>10){
        printf("O valor de n nao pode ser maior que 10, introduza n de novo:\n");
        scanf("%d", &n);
    }
    load_mat(m, n, mat1, 1);
    load_mat(m, n, mat2, 2);
    sum_mat(m, n, mat1, mat2);
    print_mat(m, n, mat1);
}

void load_mat(int m, int n, int matriz[11][11], int e){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Introduza o valor da posicao %d %d na matriz%d:\n", i, j, e);
            scanf("%d", &matriz[i][j]);
        }
    }
    return;
}

void sum_mat(int m, int n, int mat1[11][11], int mat2[11][11]){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            mat1[i][j]+=mat2[i][j];
        }
    }
    return;
}

void print_mat(int m, int n, int mat[11][11]){
    int i, j;
    printf("A soma das matrizes e a matriz:\n");
    for(i=0;i<m;i++){
        printf("{");
        for(j=0;j<n;j++){
            printf("%d", mat[i][j]);
        }
        printf("}");
        printf("\n");
    }
    return;
}
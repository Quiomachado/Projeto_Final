#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void initablueiro(char [16][16],char [16],int [16], int);
void printabuleiro(char [16][16],char [16],int [16], int);
void editabuleiro(char [16][16], char [25], int);

int main(){
    char tabuleiro[16][16];
    int eixonum[16];
    char eixoletras[16];
    int n;
    char input[25];
    printf("Introduza o numero de linhas e colunas, este numero deve ser IMPAR e estar entre 7 e 15:\n");
    scanf("%d", &n);
    while((n<7)|| (n>15) || (n%2)==0){
        printf("Nao introduziu um valor valido, introduza um valor IMPAR entre 7 e 15:\n");
        scanf("%d", &n);
    }
    initablueiro(tabuleiro, eixoletras, eixonum, n);
    printabuleiro(tabuleiro, eixoletras, eixonum, n);
    printf("Introduza as coordenadas, seguida da orientacao e da palavra: ");
    fgets(input, 25, stdin); //descartar a mudança de linha do scanf
    fgets(input, 25, stdin);
    while((input[0]!='f' && input[1]!='i' && input[2]!='m')&&(input[0]!='F' && input[1]!='I' && input[2]!='M')){
        editabuleiro(tabuleiro, input, n);
        printabuleiro(tabuleiro, eixoletras, eixonum, n);
        printf("Introduza as coordenadas, seguida da orientacao e da palavra: ");
        fgets(input, 25, stdin);
    }
}

void initablueiro(char tabuleiro[16][16],char eixoletras[16], int eixonum[16], int n){
    int i, k;
    for(i=1;i<=n;i++){
        for(k=1;k<=n;k++){
            tabuleiro[i][k]='.';
        }
    }
    for(i=0;i<=n;i++){
        eixonum[i]=i;
        eixoletras[i]=i+'@';
    }
    for(i=1;i<=n;i++){
        for(k=1;k<=n;k++){
            if(i==k || n-i==k-1){
                tabuleiro[i][k]='2';
            }
            if(((i==1) && (k==1)) || ((i==1) && (k==n)) || ((i==n) && (k==1)) || ((i==n) && (k==n))){
                tabuleiro[i][k]='$';
            }
            if(((k==(n/2)+1)&&(i==1 || i==n))||((i==(n/2)+1)&&(k==1 || k==n))){
                tabuleiro[i][k]='3';
            }
            if((((k==(n/2))||k==((n/2)+2))&&(i==2 || i==n-1))||(((i==(n/2))||i==((n/2)+2))&&(k==2 || k==n-1))){
                tabuleiro[i][k]='#';
            }
        }
    }
}

void printabuleiro(char tabuleiro[16][16],char eixoletras[16], int eixonum[16], int n){
    int i, k;
    printf("\nEstado atual do tabuleiro:\n");
    for(i=1;i<=n;i++){
        if(i<=n){
            if(i<=9){
                printf(" %d ", eixonum[i]);
            }else{
                printf("%d ", eixonum[i]);
            }
        }
        for(k=1;k<=n;k++){
            printf("%c ", tabuleiro[i][k]);
        }
        printf("\n");
    }
    for(i=n;i<=n;i++){
        printf("   ");
        for(k=1;k<=n;k++){
            printf("%c ", eixoletras[k]);
        }
    }
    printf("\n");
}

void editabuleiro(char tabuleiro[16][16], char input[25], int n){
    int i=4, x, x2=0, y, dir, len, len_palavra, count=0, multi=1, tempx, tempy;
    char temptabuleiro[20];
    len=strlen(input);
    len_palavra=len-6;
    x=input[1]-'0';
    y=input[0]-'@';
    if(y>26){
        y=input[0]-'`';
    }
    dir=input[2]-'@';
    if(dir<0){
        x2=input[2]-'0';
        x=(x*10)+x2;
        dir=input[3]-'@';
        len_palavra=len-7;
        i=5;
    }
    if(x>n || y>n){
        printf("Introduziu coordenadas que nao pertencem!");
        return;
    }
    tempy=y;
    tempx=x;
    if(dir==8 || dir==40){
        if(len_palavra>n-y){
            printf("Introduziu uma palavra demasiado grande.");
        }else{
            while(y<=n && i<=len-2){
                temptabuleiro[y]=tabuleiro[x][y];
                if((((y==(n/2))||y==((n/2)+2))&&(x==2 || x==n-1))||(((x==(n/2))||x==((n/2)+2))&&(y==2 || y==n-1))){
                    printf("Esta palavra usa um espaco proibido!\n");
                    while(y>=tempy){
                        tabuleiro[x][y]=temptabuleiro[y];
                        y--;
                    }
                    return;
                }
                if(tabuleiro[x][y]!='.' && tabuleiro[x][y]!='$' && tabuleiro[x][y]!='2' && tabuleiro[x][y]!='3' && tabuleiro[x][y]!=input[i]){
                    printf("A sua palavra nao utiliza um carater ja colocado anteriormente!");
                    return;
                }
                if(tabuleiro[x][y]==input[i]){
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count++;
                            break;
                        case 'd':
                        case 'g':
                            count+=2;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=3;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=4;
                            break;
                        case 'k':
                            count+=5;
                            break;
                        case 'j':
                        case 'x':
                            count+=8;
                            break;
                        case 'q':
                        case 'z':
                            count+=10;
                            break;
                    }
                }else if((x==1 && y==1) || (x==1 && y==n) || (x==n && y==1) || (x==n && y==n)){
                    multi++;
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count++;
                            break;
                        case 'd':
                        case 'g':
                            count+=2;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=3;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=4;
                            break;
                        case 'k':
                            count+=5;
                            break;
                        case 'j':
                        case 'x':
                            count+=8;
                            break;
                        case 'q':
                        case 'z':
                            count+=10;
                            break;
                    }
                }else if(x==y || n-x==y-1){
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count+=2;
                            break;
                        case 'd':
                        case 'g':
                            count+=4;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=6;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=8;
                            break;
                        case 'k':
                            count+=10;
                            break;
                        case 'j':
                        case 'x':
                            count+=16;
                            break;
                        case 'q':
                        case 'z':
                            count+=20;
                            break;
                    }
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count+=3;
                            break;
                        case 'd':
                        case 'g':
                            count+=6;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=9;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=12;
                            break;
                        case 'k':
                            count+=15;
                            break;
                        case 'j':
                        case 'x':
                            count+=24;
                            break;
                        case 'q':
                        case 'z':
                            count+=30;
                            break;
                    }
                }else{
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count++;
                            break;
                        case 'd':
                        case 'g':
                            count+=2;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=3;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=4;
                            break;
                        case 'k':
                            count+=5;
                            break;
                        case 'j':
                        case 'x':
                            count+=8;
                            break;
                        case 'q':
                        case 'z':
                            count+=10;
                            break;
                    }
                }
                tabuleiro[x][y]=input[i];
                y++, i++;
            }
        }
    count*=multi;
    printf("%s%d pontos", input, count);
    }else if(dir==22 || dir==54){
        if(len_palavra>n-x){
            printf("Introduzio uma palavra demasiado grande.");
        }else{
            while(x<=n && i<=len-2){
                temptabuleiro[x]=tabuleiro[x][y];
                if((((y==(n/2))||y==((n/2)+2))&&(x==2 || x==n-1))||(((x==(n/2))||x==((n/2)+2))&&(y==2 || y==n-1))){
                    printf("Esta palavra usa um espaco proibido!\n");
                    while(x>=tempx){
                        tabuleiro[x][y]=temptabuleiro[x];
                        x--;
                    }
                    return;
                }
                if(tabuleiro[x][y]!='.' && tabuleiro[x][y]!='$' && tabuleiro[x][y]!='2' && tabuleiro[x][y]!='3' && tabuleiro[x][y]!=input[i]){
                    printf("A sua palavra nao utiliza um carater ja colocado anteriormente!");
                    return;
                }
                if(tabuleiro[x][y]==input[i]){
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count++;
                            break;
                        case 'd':
                        case 'g':
                            count+=2;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=3;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=4;
                            break;
                        case 'k':
                            count+=5;
                            break;
                        case 'j':
                        case 'x':
                            count+=8;
                            break;
                        case 'q':
                        case 'z':
                            count+=10;
                            break;
                    }
                }else if((x==1 && y==1) || (x==1 && y==n) || (x==n && y==1) || (x==n && y==n)){
                    multi++;
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count++;
                            break;
                        case 'd':
                        case 'g':
                            count+=2;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=3;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=4;
                            break;
                        case 'k':
                            count+=5;
                            break;
                        case 'j':
                        case 'x':
                            count+=8;
                            break;
                        case 'q':
                        case 'z':
                            count+=10;
                            break;
                    }
                }else if(x==y || n-x==y-1){
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count+=2;
                            break;
                        case 'd':
                        case 'g':
                            count+=4;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=6;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=8;
                            break;
                        case 'k':
                            count+=10;
                            break;
                        case 'j':
                        case 'x':
                            count+=16;
                            break;
                        case 'q':
                        case 'z':
                            count+=20;
                            break;
                    }
                }else if(((y==(n/2)+1)&&(x==1 || x==n))||((x==(n/2)+1)&&(y==1 || y==n))){
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count+=3;
                            break;
                        case 'd':
                        case 'g':
                            count+=6;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=9;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=12;
                            break;
                        case 'k':
                            count+=15;
                            break;
                        case 'j':
                        case 'x':
                            count+=24;
                            break;
                        case 'q':
                        case 'z':
                            count+=30;
                            break;
                    }
                }else{
                    switch(input[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'l':
                        case 'n':
                        case 'o':
                        case 'r':
                        case 's':
                        case 't':
                        case 'u':
                            count++;
                            break;
                        case 'd':
                        case 'g':
                            count+=2;
                            break;
                        case 'b':
                        case 'c':
                        case 'm':
                        case 'p':
                            count+=3;
                            break;
                        case 'f':
                        case 'h':
                        case 'v':
                        case 'w':
                        case 'y':
                            count+=4;
                            break;
                        case 'k':
                            count+=5;
                            break;
                        case 'j':
                        case 'x':
                            count+=8;
                            break;
                        case 'q':
                        case 'z':
                            count+=10;
                            break;
                    }
                }
                tabuleiro[x][y]=input[i];
                x++, i++;
            }
        }
    count*=multi;
    printf("%s%d pontos", input, count);
    }
}

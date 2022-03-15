#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char in[50];
    int i;
    fgets(in, sizeof(in), stdin);
    for (i = 0; in[i]!='\0'; i++)
    {       
        if(in[i]>= 'a' && in[i]<='z'){
            in[i]=in[i]-32;
        }
    }
    printf("Os carateres em letra maiuscula sao: %s", in);
} 
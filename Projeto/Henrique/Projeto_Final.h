#ifndef PROJETO_FINAL_H_INCLUDED
#define PROJETO_FINAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int get_comando(int , char *[], int *, char *, char *, int *, int *, char *, int *, char *, char *);
void initablueiro(char [16][16],char [16],int [16], int);
void printabuleiro(char [16][16],char [16],int [16], int);
void editabuleiro(char [16][16], char [25], int);
//void condicoes(int, char *, char *, char *, char *, char *, char *, char *, char *, char *);

#endif // PROJETO_FINAL_H_INCLUDED

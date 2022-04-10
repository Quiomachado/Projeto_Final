#ifndef PROJETO_FINAL_H_INCLUDED
#define PROJETO_FINAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int get_comando(int argc, char *argv[], char *t, char *d, char *l, char *m, char *n, char *i, char *j, char *o, char *r);
void initablueiro(char [16][16],char [16],int [16], int);
void printabuleiro(char [16][16],char [16],int [16], int);
void editabuleiro(char [16][16], char [25], int);

#endif // PROJETO_FINAL_H_INCLUDED

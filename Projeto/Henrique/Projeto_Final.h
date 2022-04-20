#ifndef PROJETO_FINAL_H_INCLUDED
#define PROJETO_FINAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#define MAX_SIZE 140

int get_comando(int , char *[], int *, char **, char **, int *, int *, char **, int *, char **, char **);
int get_tabuleiro(char *[16], char *, int *, char [16], int [16]);
int get_dicionario (char *, char *[140], int, int *);
int org_dicionario(char *[140], char *[140], int , int );
void initablueiro(char *[16],char [16],int [16], int);
void printabuleiro(char *[16],char [16],int [16], int);
void editabuleiro(char *[16], char [5], char [16], int);
void free_mem(int , char *[16], char *[16], int);
//void condicoes(int, char *, char *, char *, char *, char *, char *, char *, char *, char *);

#endif // PROJETO_FINAL_H_INCLUDED

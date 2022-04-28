#ifndef PROJETO_FINAL_H_INCLUDED
#define PROJETO_FINAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#define MAX_SIZE 150

int get_comando(int , char *[], int *, char **, char **, int *, int *, char **, int *, char **, char **);
int get_tabuleiro(char *[16], char *, int *, char [16], int [16], int *);
int get_dicionario (char *, char *[140], int, int *);
int org_dicionario(char *[140], char *[140], int *, int );
void initablueiro(char *[16],char [16],int [16], int);
int ver_palavra(char [5], char [16], int , char *[16], int, int, int, int);
int contar_pontos (char [16], char *[16], int , int , int, int, char [5]);
void printabuleiro(char *[16],char [16],int [16], int);
int alg_cpu(char *[16], int , char *[140], int , char [16], int, int *, int, char *);
void editabuleiro(char *[16], char [5], char [16], int, int, int, int);
void print_file(char *[16], char *, int, char [16], int [16]);
void free_mem(int , char *[16], char *[16], int);

#endif // PROJETO_FINAL_H_INCLUDED

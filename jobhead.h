#ifndef JOBHEAD_H_INCLUDED
#define JOBHEAD_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#include<string.h>
#define chronum 201
#define age 500
#define Pmutate 0.9
#define Pcross 0.2
#define Nextgen chronum*Pmutate+chronum*Pcross
extern int **Ma;
extern int **Ti;
extern int N;
extern int M;
extern int *n_num;
extern int **ChroOne;
extern int ProcedureTotal;
extern int *FitFather;
extern int *FitSon;
extern int **ChroTwo;
extern int **ChroSon;
extern int *average;
extern int generation;
//遗传算法
extern int GreatGeneNum;
extern int* GreatGeneChain;

void Allocate();
void freepointer();

void GetGreatGene();
int DeNormalGene(int* NormalGeneChain);
int Gene_initialize();
void Gene_decode();
void Roulette();
void Championships();

int Gene_evolveodd();
int Gene_mutateodd(int flag);
int Gene_cross1odd(int flag);
int Gene_cross2odd(int a,int b,int flag);
int Gene_evolveeven();
int Gene_mutateeven(int flag);
int Gene_cross1even(int flag);
int Gene_cross2even(int a,int b,int flag);
//其他函数
void Fitness();
int Max(int a,int b);
int input();
void Table(int* NormalGeneChain);
#endif // JOBHEAD_H_INCLUDED

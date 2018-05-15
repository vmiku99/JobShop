#ifndef JOBHEAD_H_INCLUDED
#define JOBHEAD_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#define chronum 101
extern int **Ma;
extern int **Ti;
extern int N;
extern int M;
extern int *n_num;
extern int **ChroOne;
extern int ProcedureTotal;
//开始

extern int *FitFather;
extern int *FitSon;
extern int **ChroTwo;
extern int **ChroSon;


//结束
//遗传算法
extern int GreatGeneNum;
extern int* GreatGeneChain;
void Allocate();
void GetGreatGene();
int DeNormalGene(int* NormalGeneChain);
int Gene_initialize();
void Gene_decode();
int Gene_evolve(int **Chromosome);
int Gene_mutate(int **Chromosome,int flag);
int Gene_cross1(int **Chromosome,int flag);
int Gene_cross2(int a,int b,int **Chromosome,int flag);
void Roulette(int generation);
//其他函数
int Max(int a,int b);
int input();
void Fitness(int generation);
//
#endif // JOBHEAD_H_INCLUDED

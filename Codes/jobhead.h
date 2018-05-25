#ifndef JOBHEAD_H_INCLUDED
#define JOBHEAD_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#include<string.h>
#define chronum 201
#define age 200
#define Pcross 0.9
#define Pmutate 0.2
#define Nextgen (chronum-1)*Pcross+1
extern int **Ma;
extern int **Ti;
extern int N;
extern int M;
extern int *n_num;
extern int ProcedureTotal;
extern int **ChroOne;
extern int **ChroTwo;
extern int **ChroSon;
extern int *FitFather;
extern int *FitSon;
extern int *average;
extern int generation;
//�Ŵ��㷨
extern int GreatGeneNum;
extern int* GreatGeneChain;

void Allocate();
void freepointer();

void GetGreatGene();
int decode(int* NormalGeneChain);
int Gene_initialize();
void Gene_decode();
void Roulette();
void Championships();
//int Gene_evolveodd();
//int Gene_mutateodd(int flag);
//int Gene_cross1odd(int flag);
//int Gene_cross2odd(int a,int b,int flag);
//int Gene_evolveeven();
//int Gene_mutateeven(int flag);
//int Gene_cross1even(int flag);
//int Gene_cross2even(int a,int b,int flag);
int evolve(int g);
int cross(int flag,int g);
int mutate(int flag,int g);
int check(int *a,int recent);
void freethem();
int dfs1(int flag,int step);
int dfs2(int flag,int step);
//��������
void Fitness();
int Max(int a,int b);
int input();
void Table(int* NormalGeneChain);
#endif // JOBHEAD_H_INCLUDED
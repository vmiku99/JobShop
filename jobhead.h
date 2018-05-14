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
extern int **Chro;
extern int ProcedureTotal;
//遗传算法
int Gene_initialize();
void Gene_decode();
//其他函数
int Max(int a,int b);
//
#endif // JOBHEAD_H_INCLUDED

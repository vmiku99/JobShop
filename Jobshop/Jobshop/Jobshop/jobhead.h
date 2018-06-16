#ifndef JOBHEAD_H_INCLUDED
#define JOBHEAD_H_INCLUDED
//#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#include<string.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#define Pcross 0.9                            //杂交率
#define Pmutate 0.3                           //变异率
extern int chronum;                           //染色体数
extern int age;                               //进化代数
extern int Nextgen;                           //下一代染色体个数
extern int **Ma;                              //记录机器
extern int **Ti;                              //记录时间
extern int N;                                 //记录工件数
extern int M;                                 //记录机器数
extern int *n_num;                            //记录每个工件的工序数
extern int ProcedureTotal;                    //记录总工序数
extern int **ChroOne;                         //染色体群1
extern int **ChroTwo;                         //染色体群2
extern int **ChroSon;                         //子代染色体
extern int *FitFather;                        //父代适应度
extern int *FitSon;                           //子代适应度
extern int average;                          //适应度平均值
extern int generation;                        //更新多少代
extern clock_t start;                         //时间长度
											  //最短记录
extern int GreatGeneNum;                      //最短时间
extern int* GreatGeneChain;                   //最短时间的染色体
											  //为染色体分配空间
void Allocate();
void Allocate2();
void freepointer();
//染色体的一系列操作
void GetGreatGene();                          //获得最好基因
int decode(int* NormalGeneChain);             //解码
int Gene_initialize();                        //初始化种群
											  //选择算法
void Roulette();                              //轮盘赌
void Championships();                         //锦标赛
											  //进化变异操作
int addChro();                                //增加染色体
int evolve();                                 //进化
int cross(int flag);                          //杂交
int mutate(int flag);                         //变异
int check(int *a, int recent);                 //一个检测函数，用来查重
int dfs1(int flag, int step);                  //两个深搜用来全排列
int dfs2(int flag, int step);
void freethem();                              //释放指针
											  //输出函数
struct Result {
	int start;
	int stop;
	int times;
	int tool;
	int kind;
	struct Result* next;

};                                            //用来存储的结构体
void OutPut(int* NormalGeneChain);            //输出函数
void Paint(int* NormalGeneChain);
void Freestruct(struct Result* rr);           //释放指针
											  //其他函数
void Fitness();                     //适应度函数
int Max(int a, int b);               //比较大小
int input();                        //输入函数
int input2();
void Table(int* NormalGeneChain);   //打表
void Paint(int* NormalGeneChain);
COLORREF cococolor(int MM);
void TcharToChar(const TCHAR * tchar, char * _char);
#endif // JOBHEAD_H_INCLUDED

/*********************************************************/
/*  direct.h                                             */
/*                                                       */
/*  ナップサック問題 全探索プログラム                    */
/*                                                       */
/*                                                       */
/*********************************************************/
#ifndef _DIRECT_H_
#define _DIRECT_H_

#include <stdio.h>
#include <stdlib.h>
#include "rnd.h"

/*  データ構造                               */
#define MAXVALUE 100                     /* 重さと価値の最大値    */
#define N 30                             /* 荷物の個数    */
#define POOLSIZE 30                      /* プールサイズ  */
#define WEIGHTLIMIT (N * MAXVALUE / 4)   /* 重量制限  */

typedef struct{
	int parcel[N][2];        /* 荷物     */
} Parcel;


/*  関数                       */
void initparcel(Parcel *parcel);   // 荷物の初期化
void getparcel(Parcel *pa);        // 荷物の値出力

int solve(Parcel *pa);             // 探索の本体
int pow2n(int n);                  // 2のべき乗
int calcval(int i, Parcel *pa);    // 評価値の計算
void prints(int solution);         // 解候補の出力

#endif


/*********************************************************/
/*  rnd.h                                                */
/*                                                       */
/*  乱数生成プログラム                                   */
/*                                                       */
/*                                                       */
/*********************************************************/
#ifndef _RND_H_
#define _RND_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/*  乱数生成 関数                       */
double rand1();                      // 0〜1の実数を返す
int rand01();                        // 0 or 1 の整数を返す
int rand100();                       // 0〜100の整数を返す
int rndn(int n);                     // n未満の乱数生成

#endif


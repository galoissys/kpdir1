/*********************************************************/
/*  direct.c                                             */
/*                                                       */
/*  ナップサック問題 全探索プログラム                    */
/*                                                       */
/*                                                       */
/*********************************************************/
#include "direct.h"

/*  関数                       */

/*********************************************************/
/* initparcel() : 荷物の初期化                           */
/*********************************************************/
void initparcel(Parcel *pa){
	
	int i=0;
	
	srand((unsigned)time(NULL));    /* time関数を用いた乱数初期化の定番式 */
	
	for(i=0; i < N; ++i){
		pa->parcel[i][0] = rndn(MAXVALUE);
		pa->parcel[i][1] = rndn(MAXVALUE);
	}
	
	// while( (i < N) && (scanf("%d %d", &pa->parcel[i][0], &pa->parcel[i][1]) != EOF) ){
	// 	++i;
	// }
	
}


/*********************************************************/
/* getparcel() : 荷物の値出力                            */
/*********************************************************/
void getparcel(Parcel *pa){
	
	int i=0;
	
	for(i=0; i < N; ++i){
		printf("parcel %d:\t", i);
		printf("weight = %d\t", pa->parcel[i][0]);
		printf("value = %d\n", pa->parcel[i][1]);
	}
	
}


/*********************************************************/
/* solve() : 探索の本体                                  */
/*********************************************************/
int solve(Parcel *pa){
	
	int i=0;
	int limit;         /*  探索の上限   */
	int maxvalue =0;   /*  評価値の最大値   */
	int value;         /*  評価値   */
	int solution;      /*  解候補   */
	
	/*  探索範囲の設定   */
	limit = pow2n(N);
	
	/*  解の探索   */
	for(i=0; i < limit; ++i){
		
		/*  評価値の計算   */
		value = calcval(i, pa);
		
		/*  最大値の更新   */
		if(value > maxvalue){
			maxvalue = value;
			solution = i;
			printf("*** maxvalue = %d\n", maxvalue);
		}
		
	}
	
	return solution;
}


/*********************************************************/
/* pow2n() : 2のべき乗                                   */
/*********************************************************/
int pow2n(int n){
	
	int i=0;
	int pow = 1;
	
	for(i=n; i > 0; --i){
		pow *= 2;
	}
	
	return pow;
	
}


/*********************************************************/
/* calcval() : 評価値の計算                              */
/*********************************************************/
int calcval(int i, Parcel *pa){
	
	int pos;           /*  遺伝子座の指定   */
	int value = 0;     /*  評価値   */
	int weight = 0;    /*  重量   */
	
	/*  各遺伝子座を調べて重量と評価値を計算   */
	for(pos = 0; pos < N; ++pos){
		/*  iを2進数で表すと例えば10110...011となる   */
		/*  変数posにより、右に一つずつシフトしていくと各桁の数値（0 or 1）が取得できる   */
		weight += pa->parcel[pos][0] * ( (i >> pos) & 0x1 );
		value += pa->parcel[pos][1] * ( (i >> pos) & 0x1 );
	}
	
	/*  致死遺伝子の処理   */
	if(weight >= WEIGHTLIMIT) value = 0;
	
	return value;
}


/*********************************************************/
/* prints() : 解候補の出力                               */
/*********************************************************/
void prints(int solution){
	
	int i=0;
	
	for(i=0; i < N; ++i){
		printf("%1d ", (solution >> i) & 0x1);
	}
	printf("\n");
	
}



/*********************************************************/
/*  kpdir.c                                              */
/*                                                       */
/*  ナップサック問題 全探索プログラム                    */
/*                                                       */
/*                                                       */
/*********************************************************/
#include "kpdir.h"

int kpdir(){
	
	/*  荷物の初期化   */
	Parcel pal, *ppal;
	ppal = &pal;
	
	initparcel(ppal);
	getparcel(ppal);
	
	/*  探索の本体     */
	int solution = 0xfff;  /*  解  */
	solution = solve(ppal);
	
	/*  解の出力   */
	prints(solution);
	
	
	return 0;
}



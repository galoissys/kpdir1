/*********************************************************/
/*  kpdir.c                                              */
/*                                                       */
/*  �i�b�v�T�b�N��� �S�T���v���O����                    */
/*                                                       */
/*                                                       */
/*********************************************************/
#include "kpdir.h"

int kpdir(){
	
	/*  �ו��̏�����   */
	Parcel pal, *ppal;
	ppal = &pal;
	
	initparcel(ppal);
	getparcel(ppal);
	
	/*  �T���̖{��     */
	int solution = 0xfff;  /*  ��  */
	solution = solve(ppal);
	
	/*  ���̏o��   */
	prints(solution);
	
	
	return 0;
}



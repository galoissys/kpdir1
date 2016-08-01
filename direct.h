/*********************************************************/
/*  direct.h                                             */
/*                                                       */
/*  �i�b�v�T�b�N��� �S�T���v���O����                    */
/*                                                       */
/*                                                       */
/*********************************************************/
#ifndef _DIRECT_H_
#define _DIRECT_H_

#include <stdio.h>
#include <stdlib.h>
#include "rnd.h"

/*  �f�[�^�\��                               */
#define MAXVALUE 100                     /* �d���Ɖ��l�̍ő�l    */
#define N 30                             /* �ו��̌�    */
#define POOLSIZE 30                      /* �v�[���T�C�Y  */
#define WEIGHTLIMIT (N * MAXVALUE / 4)   /* �d�ʐ���  */

typedef struct{
	int parcel[N][2];        /* �ו�     */
} Parcel;


/*  �֐�                       */
void initparcel(Parcel *parcel);   // �ו��̏�����
void getparcel(Parcel *pa);        // �ו��̒l�o��

int solve(Parcel *pa);             // �T���̖{��
int pow2n(int n);                  // 2�ׂ̂���
int calcval(int i, Parcel *pa);    // �]���l�̌v�Z
void prints(int solution);         // �����̏o��

#endif


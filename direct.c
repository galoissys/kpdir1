/*********************************************************/
/*  direct.c                                             */
/*                                                       */
/*  �i�b�v�T�b�N��� �S�T���v���O����                    */
/*                                                       */
/*                                                       */
/*********************************************************/
#include "direct.h"

/*  �֐�                       */

/*********************************************************/
/* initparcel() : �ו��̏�����                           */
/*********************************************************/
void initparcel(Parcel *pa){
	
	int i=0;
	
	srand((unsigned)time(NULL));    /* time�֐���p���������������̒�Ԏ� */
	
	for(i=0; i < N; ++i){
		pa->parcel[i][0] = rndn(MAXVALUE);
		pa->parcel[i][1] = rndn(MAXVALUE);
	}
	
	// while( (i < N) && (scanf("%d %d", &pa->parcel[i][0], &pa->parcel[i][1]) != EOF) ){
	// 	++i;
	// }
	
}


/*********************************************************/
/* getparcel() : �ו��̒l�o��                            */
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
/* solve() : �T���̖{��                                  */
/*********************************************************/
int solve(Parcel *pa){
	
	int i=0;
	int limit;         /*  �T���̏��   */
	int maxvalue =0;   /*  �]���l�̍ő�l   */
	int value;         /*  �]���l   */
	int solution;      /*  �����   */
	
	/*  �T���͈͂̐ݒ�   */
	limit = pow2n(N);
	
	/*  ���̒T��   */
	for(i=0; i < limit; ++i){
		
		/*  �]���l�̌v�Z   */
		value = calcval(i, pa);
		
		/*  �ő�l�̍X�V   */
		if(value > maxvalue){
			maxvalue = value;
			solution = i;
			printf("*** maxvalue = %d\n", maxvalue);
		}
		
	}
	
	return solution;
}


/*********************************************************/
/* pow2n() : 2�ׂ̂���                                   */
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
/* calcval() : �]���l�̌v�Z                              */
/*********************************************************/
int calcval(int i, Parcel *pa){
	
	int pos;           /*  ��`�q���̎w��   */
	int value = 0;     /*  �]���l   */
	int weight = 0;    /*  �d��   */
	
	/*  �e��`�q���𒲂ׂďd�ʂƕ]���l���v�Z   */
	for(pos = 0; pos < N; ++pos){
		/*  i��2�i���ŕ\���ƗႦ��10110...011�ƂȂ�   */
		/*  �ϐ�pos�ɂ��A�E�Ɉ���V�t�g���Ă����Ɗe���̐��l�i0 or 1�j���擾�ł���   */
		weight += pa->parcel[pos][0] * ( (i >> pos) & 0x1 );
		value += pa->parcel[pos][1] * ( (i >> pos) & 0x1 );
	}
	
	/*  �v����`�q�̏���   */
	if(weight >= WEIGHTLIMIT) value = 0;
	
	return value;
}


/*********************************************************/
/* prints() : �����̏o��                               */
/*********************************************************/
void prints(int solution){
	
	int i=0;
	
	for(i=0; i < N; ++i){
		printf("%1d ", (solution >> i) & 0x1);
	}
	printf("\n");
	
}



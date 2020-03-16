
#include <stdlib.h>
#include <stdio.h>

void main(void){
	int A[6] = {1, 3, 4, 6, 8, 10};
	int B[5] = {9, 8, 7, 4, 2};
	int C[5+6]={};
    
    printf("\n");
	for(unsigned int i=0; i<6; i++){
		C[i]=A[i];
	}
    for(unsigned int i=6, j=0; i<5+6, j<5; i++, j++){
		C[i]=B[j];
	}
/**************Logic part*****************/
	int accum = 0;
	for(unsigned int i=0; i<5+6; i++){
		if(i == 5+6-1)
			break;
		for(unsigned int j=i+1; j<5+6; j++){
			if(C[j]<C[i]){
				accum = C[i];
				C[i] = C[j];
				C[j] = accum;
			}
		}
	}
/******************************************/
	for(unsigned int i=0; i<5+6; i++)
		printf("  %d", C[i]);
}
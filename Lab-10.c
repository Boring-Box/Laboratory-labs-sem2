/******************************************************************************
 | 0,42x(1)-1,13x(2)+7,05x(3)=6,15;
<  1,14x(1)-2,15x(2)+5,11x(3)=-4,16;
 \ -0,71x(1)+0,81x(2)-0,02x(3)=-0,17;
*******************************************************************************/
#include <stdio.h>

int main()
{	int i, j, k;
    float oo, diag, root;
    int n=0, m=0;
    
	START:

    system("cls");
    printf("%d\n", sizeof(short unsigned int));
    printf("\aEnter size of the matrix !(m=n+1)! :");
    printf("\nn = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    
	if(m!=n+1)
		goto START;
    float A[n][m];
//***************MATRIX INPUT*********************************
	system("cls");
    printf("Refull the matrix\n");
    for(i=0, oo=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &oo);
            A[i][j]=oo;
        }
    }
/* //******************TEST MATRIX*******************************
	A[0][0]=3.21; A[0][1]=-4.15; A[0][2]=2.13; A[0][3]=5.06;
	A[1][0]=7.09; A[1][1]=1.17; A[1][2]=-2.23; A[1][3]=4.75;
	A[2][0]=0.43; A[2][1]=-1.4; A[2][2]=-0.62; A[2][3]=-1.05;
//************************************************************ */
	system("cls");
	printf("MATRIX\n");
	for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("|%.2f| ", A[i][j]);
            if(j==3)
                printf("\n");
        }
    }    
//*********************MATRIX TRANSFORMATION*******************
	for(k=0; k<n; k++){
		diag=A[k][k];
		for(i=k, j=0; j<m; j++){
			A[i][j] /= diag;
		}
		for(int a=k+1; a<n; a++){
			oo = -A[a][k];
			for(i=k, j=0; j<m; j++){
				A[a][j] += A[i][j]*oo;
			}
		}
	}
/* //*************************************************************
	printf("\nAFTER\n");
	for(i=0; i<n; i++){
    	for(j=0; j<m; j++){
            printf("|%.2f| ", A[i][j]);
            if(j==3)
                printf("\n");
        }
    }
*/
//***************************ROOTS*****************************
	printf("\n");
	root=A[n-1][m-1];
	printf("Root %d = %f", n, root);
	for(int stolbnum=m-2, rootnum=n-1, count=2, run=1; stolbnum>=0, rootnum>1, count<=n+1; stolbnum--, rootnum--, count++, run++){
		for(i=n-count; i>=0; i--){
			A[i][stolbnum]*=root;
		}
		if(rootnum>=1){
			for(int a=2; a<=count; a++){
				A[n-count][m-1]=A[n-count][m-1]-A[n-count][m-a];
			}
			root=A[n-count][m-1];
			printf("\nRoot %d = %f", rootnum, root);
		}
	}
	
	return(0);
}

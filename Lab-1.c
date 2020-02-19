/******************************************************************************
 | 0,42x(1)-1,13x(2)+7,05x(3)=6,15;
<  1,14x(1)-2,15x(2)+5,11x(3)=-4,16;
 \ -0,71x(1)+0,81x(2)-0,02x(3)=-0,17;
*******************************************************************************/

#include <stdio.h>
#include <stdio.h>

void main(void)
{   int i, j, k;
    float oo;
    int m=3, n=4;
    float A[m][n];
    printf("refull the matrix");
    for(i=0, oo=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("\nA[%d][%d] = ", i, j);
            scanf("%f", &oo);
            A[i][j]=oo;
        }
    }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("|%.2f| ", A[i][j]);
            if(j==3)
                printf("\n");
        }
    }

}
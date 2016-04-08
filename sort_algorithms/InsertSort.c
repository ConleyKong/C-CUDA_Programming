/*************************************************************************
	> File Name: InsertSort.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月02日 星期六 15时46分11秒
 ************************************************************************/

#include<stdio.h>


void
InsertionSort(int A[  ], int N )
{
    int j, P;

//    Element Type Temp;

    for ( P = 1; P < N; P ++ )
    {
        int Temp = A[ P ];
        for( j = P; j > 0 && A[ j - 1 ] > Temp; j -- )
        {
            A[ j ] = A[ j - 1 ];
        }
        A[ j ] = Temp;
    }
}

void main()
{
    int mark;
    int A[] = {3,5,3,7,6,5,4,7,8,12,34,32,12,34,213,12,21,12,32,43,54,65,3,5,6,9,76,56};
    InsertionSort(A, 28);
    for(mark = 0; mark < 28; mark ++)
    {
        printf("%d  ",A[mark]);
    }
}


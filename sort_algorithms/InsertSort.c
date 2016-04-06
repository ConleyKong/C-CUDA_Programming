/*************************************************************************
	> File Name: InsertSort.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月02日 星期六 15时46分11秒
 ************************************************************************/

#include<stdio.h>


void
InsertionSort( ElementType A[  ], int N )
{
    int j, P;

    Element Type Temp;
    for ( P = 1; P < N; P ++ )
    {
        Temp = A[ P ];
        for( j = P; j > 0 && A[ j - 1 ] > Temp; j -- )
        {
            A[ j ] = A[ j - 1 ];
        }
        A[ j ] = Temp;
    }
}

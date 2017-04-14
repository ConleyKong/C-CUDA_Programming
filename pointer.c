/*************************************************************************
	> File Name: pointer.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Apr 2017 03:50:19 PM CST
 ************************************************************************/

#include<stdio.h>
void main()
{
    int * p;
    char a;
    a = 'k';
    p = &a;
    printf("value in p: %p\n",p);
    printf("value in what p points to: %c\n", *p);
}

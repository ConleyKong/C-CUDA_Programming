/*************************************************************************
	> File Name: ShellSort.c
	> Author: james
	> Mail: lengjiabing@gmail.com
	> Created Time: 2016年04月06日 星期三 20时08分27秒
    > Shell Sorting
    > Shell Sorting--invented by Donald Shell.
 ************************************************************************/

#include<stdio.h>
#include<time.h>
//a sequence name increment sequence is the key engine of shell sorting.
//one of the most important charctiristic of shell sorting is that, every
//k th sorting, is stable for the k-1 th sorting.
/** here is an example of usting time counting function of C
 * int plus(int iEnd)
 * {
 *  int i = 0;
 *  while(i < iEnd)
 *      i ++;
 *  return i;
 * }
 *
 * clock_t start_time, end_time;
 * float total_time = 0;
 * start_time = clock();
 * plus(20000);
 * end_time = clock();
 * total_time = (float)(end_time - start_time);
 */
 float 
 ShellSort(int beforeSort[], int increament[])
 {
     clock_t start_time, end_time;
     start_time = clock();
     
     
     end_time = clock();
     total_tiem = (float)(end_time - start_time);
     
     return total_time;
 }

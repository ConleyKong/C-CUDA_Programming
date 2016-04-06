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
//有一点先写在这儿，希尔排序在规模很大的时候，可以进行并行，但是需要考虑
//并行的时候GPU共享内存与私有内存之间的通信开销是否适合进行并行的问题。
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
 ShellSort(int beforeSort[], int increment[])
 {
     clock_t start_time, end_time;
     start_time = clock();
    
     int incrementLength = sizeof(increment) / sizeof(increment[0]);
     int sortingLength = sizeof(beforeSort) /sizeof(beforeSort[0]);

     int outCircle, middleCircle, innerCircle;
     for(outCircle = 0; outCircle < incrementLength; outCircle ++)
     {
         int incrementNumber = increment[outCircle];
         for(middleCircle = 0; middleCircle < incrementNumber; middleCircle ++)
         {
             int Temp = 0;
             for(innerCircle = 0; innerCircle < sortingLength && 
                 beforeSort[innerCircle] > beforeSort[innerCircle + incrementNumber]; 
                 innerCircle += incrementNumber)
             {
                 beforeSort[innerCircle] = beforeSort[innerCircle + incrementNumber];
                 beforeSort[]
             }
         }
     }

     end_time = clock();
     total_tiem = (float)(end_time - start_time);
     
     return total_time;
 }

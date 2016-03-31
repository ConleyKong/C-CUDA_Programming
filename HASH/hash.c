/*************************************************************************
	> File Name: hash.c
	> Author:james leng 
	> Mail:lengjiabing@gmail.com
	> Created Time: 2016年03月31日 星期四 23时11分23秒
 ************************************************************************/

#include<stdio.h>

// Index is the hash address returned from hash function.
typedef unsigned int Index;

// hash function #1, due to a char's ASCII code.
Index Hash(const char *Key, int TableSize)
{
    unsigned int HashVal = 0;
    
    while( *Key != '\0' )
        HashVal += *Key ++;

    return HashVal % TableSize
}



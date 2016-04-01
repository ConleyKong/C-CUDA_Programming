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
Index Hash_ASCII_BASED(const char *Key, int TableSize)
{
    unsigned int HashVal = 0;
    
    while( *Key != '\0' )
        HashVal += *Key ++;

    return HashVal % TableSize;
}

// hash function #2, due to reflection function.i
Index Hash_FUNCTION_BASED_BAD(const char *Key, int TableSize)
{
    return ( Key[ 0 ] + 27 * Key[ 1 ] + 729 * Key[ 2 ] ) % TableSize;
}

// hash function #3, due to reflection function.ii
Index Hash_FUNCTION_BASED_GOOD(const char *Key, int TableSize)
{
    unsigned int HashVal = 0;

    while( *Key != '\0' )
        HashVal = ( HashVal << 5 ) + *Key ++;

    return HashVal % TableSize;
}


//testing main function.
int main()
{

    Index testHashIndex = Hash("testing", 128);
    printf("hash key value is :%d", testHashIndex);
}

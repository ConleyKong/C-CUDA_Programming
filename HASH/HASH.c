/*************************************************************************
	> File Name: HASH.c
	> Author:james 
	> Mail: lengjiabing@gmail.com
	> Created Time: 2016年04月01日 星期五 20时34分31秒
 ************************************************************************/

#include<stdio.h>

//定义分离链表
#ifndef _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

//定义基本操作
HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, HashTable H );
ElementType Retrieve( Position P );

/*TODO 待添加删除、创建空表等方法*/

#endif /* _HashSep_H */


struct ListNode
{
    ElementType Element;
    Position Next;
};


typedef Position List;

struct HashTbl
{
    int TableSize;
    List *TheLists;
}

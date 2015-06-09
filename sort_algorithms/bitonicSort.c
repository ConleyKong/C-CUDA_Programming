//BitonicSort,双调排序
#include <iostream>  
using namespace std;  
void SortDown(int , int);  
void MergeUp(int, int);  
void MergeDown(int, int);  
void Exchange(int , int);  
void SortUp(int, int);  
const int MAXNUM = 99999999; //如果个数不为2的次幂个，要填充的数字  
int arr[1024] = {  
    3, 1, 5, 9,  
    7, 6, 4, 2,  
    10, 25, 13, 16,  
    8, 11, 14, 15,  
    22  
};  
int main()  
{  
    int n = 17; //要排序的元素的个数  
    int flag = 0;  
    int len = 1;  
    while (len < n)//循环退出的条件 len >= n  
     len = len << 1;//左移一位相当于乘以2  
  
    if (len > n)//如果len > n,就说明数组的个数不够，要将个数填充到len个  
    {  
        flag = 0;  
        for (int i = n; i < len; i++)  
          arr[i] = MAXNUM;  
    }  
    //len = n的话，说明元素的个数恰好是2的次幂个  
    SortUp(0, len);  
    cout<<"The Sorted Result is:"<<endl;  
    for (int i = 0; i < n; i++)  
        cout << arr[i] << " ";  
      
    cout << endl;  
    system("pause");  
}  
  
void SortUp(int beg,int n)  
{  
    if(n == 1)  
    return;  
  
    SortUp(beg,n / 2);//把前面的n/2个元素按递增排序  
    SortDown(beg + n / 2, n / 2);//把后面n/2个元素按递减排序  
    MergeUp(beg, n);//合并前面n/2个和后面n/2个数组。  
    return;  
}  
  
void SortDown(int beg,int n)//类似SortUp，只是按照递减排序数组从beg开始的n个元素  
{  
    if(n == 1)  
        return;  
    SortUp(beg, n / 2); //把前面的n/2个元素按递增排序  
    SortDown(beg + n / 2, n / 2); //把后面n/2个元素按递减排序  
    MergeDown(beg, n); //合并前面n/2个和后面n/2个数组。  
}  
  
  
void MergeUp(int beg,int n)//按照从小到大的顺序合并  
{  
    if(n == 1) return;  
    int halfN = n >> 1; //向右移一位等同于除以2  
  
    for(int i = beg; i < beg + halfN; i++)  
    {  
        if(arr[i] > arr[i + halfN])  
        Exchange(i, i + halfN);  
    }  
    MergeUp(beg, halfN);  
    MergeUp(beg + halfN, halfN);  
}  
  
void MergeDown(int beg,int n) //按照从大到小的顺序合并  
{  
    if(n == 1) return;  
    int halfN = n >> 1;  
    for(int i = beg; i < beg + halfN; i++) //这一步做的是使前后两排相对应位置上的数按照从大到小排列  
    {  
        if(arr[i] < arr[i + halfN])  
        Exchange(i, i + halfN);  
    }  
    MergeDown(beg, halfN); //前半部分也要按照从大到小的顺序排列  
    MergeDown(beg + halfN, halfN); //后半部分也要按照从大到小排列  
}  
  
void Exchange(int i, int j)  
{  
    int temp = arr[i];  
    arr[i] = arr[j];  
    arr[j] = temp;  
}  
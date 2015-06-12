//BitonicSort,˫������
#include <iostream>  
using namespace std;  
void SortDown(int , int);  
void MergeUp(int, int);  
void MergeDown(int, int);  
void Exchange(int , int);  
void SortUp(int, int);  
const int MAXNUM = 99999999; //���������Ϊ2�Ĵ��ݸ���Ҫ��������  
int arr[1024] = {  
    3, 1, 5, 9,  
    7, 6, 4, 2,  
    10, 25, 13, 16,  
    8, 11, 14, 15,  
    22  
};  
int main()  
{  
    int n = 17; //Ҫ�����Ԫ�صĸ���  
    int flag = 0;  
    int len = 1;  
    while (len < n)//ѭ���˳������� len >= n  
     len = len << 1;//����һλ�൱�ڳ���2  
  
    if (len > n)//���len > n,��˵������ĸ���������Ҫ��������䵽len��  
    {  
        flag = 0;  
        for (int i = n; i < len; i++)  
          arr[i] = MAXNUM;  
    }  
    //len = n�Ļ���˵��Ԫ�صĸ���ǡ����2�Ĵ��ݸ�  
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
  
    SortUp(beg,n / 2);//��ǰ���n/2��Ԫ�ذ���������  
    SortDown(beg + n / 2, n / 2);//�Ѻ���n/2��Ԫ�ذ��ݼ�����  
    MergeUp(beg, n);//�ϲ�ǰ��n/2���ͺ���n/2�����顣  
    return;  
}  
  
void SortDown(int beg,int n)//����SortUp��ֻ�ǰ��յݼ����������beg��ʼ��n��Ԫ��  
{  
    if(n == 1)  
        return;  
    SortUp(beg, n / 2); //��ǰ���n/2��Ԫ�ذ���������  
    SortDown(beg + n / 2, n / 2); //�Ѻ���n/2��Ԫ�ذ��ݼ�����  
    MergeDown(beg, n); //�ϲ�ǰ��n/2���ͺ���n/2�����顣  
}  
  
  
void MergeUp(int beg,int n)//���մ�С�����˳��ϲ�  
{  
    if(n == 1) return;  
    int halfN = n >> 1; //������һλ��ͬ�ڳ���2  
  
    for(int i = beg; i < beg + halfN; i++)  
    {  
        if(arr[i] > arr[i + halfN])  
        Exchange(i, i + halfN);  
    }  
    MergeUp(beg, halfN);  
    MergeUp(beg + halfN, halfN);  
}  
  
void MergeDown(int beg,int n) //���մӴ�С��˳��ϲ�  
{  
    if(n == 1) return;  
    int halfN = n >> 1;  
    for(int i = beg; i < beg + halfN; i++) //��һ��������ʹǰ���������Ӧλ���ϵ������մӴ�С����  
    {  
        if(arr[i] < arr[i + halfN])  
        Exchange(i, i + halfN);  
    }  
    MergeDown(beg, halfN); //ǰ�벿��ҲҪ���մӴ�С��˳������  
    MergeDown(beg + halfN, halfN); //��벿��ҲҪ���մӴ�С����  
}  
  
void Exchange(int i, int j)  
{  
    int temp = arr[i];  
    arr[i] = arr[j];  
    arr[j] = temp;  
}  
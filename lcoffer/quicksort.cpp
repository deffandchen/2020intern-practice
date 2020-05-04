#include<iostream>
//#include<algorithm>
using namespace std;

void insertSort(int A[],int n)
{
    int j;
    for(int i=1;i<n;i++)
    {
        int tmp = A[i];
        for(j = i;j>0 && A[j-1]>tmp;j--)
            A[j] = A[j-1];
        A[j] = tmp;
    }
}

int parition(int A[],int left,int right)
{
    int mid = (left + right)/2;
    if(A[left] > A[mid])
        swap(A[left],A[mid]);
    if(A[left] > A[right])
        swap(A[left],A[right]);
    if(A[mid] > A[right])
        swap(A[mid] , A[right]);
    
    swap(A[mid],A[right-1]);

    return A[right-1];
}

void quickSort(int A[],int left,int right)
{
    if(left + 3 < right)
    {
        int povit = parition(A,left,right);
        int i = left;
        int j = right-1;
        for(;;)
        {
            while(A[++i] < povit) {}
            while(A[--j] > povit) {}
            if(i>j)
                break;
            swap(A[i],A[j]);
        }
        swap(A[i],A[right-1]);
        quickSort(A,left,i);
        quickSort(A,i+1,right);
    }
    else
        insertSort(A+left,right-left+1);
}

int main()
{
    int A[10] = {10,2,56,0,3,256,384,3,208,65};
    quickSort(A,0,9);
    for(int i=0;i<10;i++)
    {
        cout << A[i] << ' ';
    }
    cout<<endl;
    return 0;
}
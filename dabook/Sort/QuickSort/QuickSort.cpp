#include<iostream>
#include<string>
using namespace std;

void InsetSort(int A[],int N)
{
    int p,j;
    for(p = 1; p<N; p++)
    {
        int temp = A[p];
        for(j = p; j>0 && A[ j-1 ] > temp;j--)
            A[j] = A[ j-1 ];
        A[j] = temp;
    }
}

void swap(int *a, int *b)  //交换数组中两个位置的值
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int median3(int A[], int left, int right)
{
    int center = (left + right) / 2;
    if(A[left] > A[center])
        swap(&A[left], &A[center]);
    if(A[left] > A[right])
        swap(&A[left], &A[right]);
    if(A[center] > A[right])
        swap(&A[center], &A[right]);
    
    swap(&A[center], &A[right-1]);
    return A[ right-1 ];
}

void Qsort(int A[], int left, int right)
{
    if(left + 3 < right)
    {
        int i = left, j = right -1;
        int pivot = median3(A, left, right);
        for(;;)
        {
            while(A[ ++i ] < pivot) {}
            while(A[ --j ] > pivot) {}
            if(i < j) 
                swap(&A[i], &A[j]);
            else 
                break;
        }
        for(int l=0; l <= right; l++)
            std::cout << A[l] << " ";
        std::cout<<std::endl;

        swap(&A[i], &A[right-1]);
        /*
        for(int l=0; l <= right; l++)
            std::cout << A[l];
        std::cout<<std::endl;
        */
        Qsort(A,left,i-1);
        Qsort(A,i+1,right);
    }
    else
        InsetSort(A+left,right-left+1);
}

int main()
{
    int A[5] = {1,4,3,6,2};
    //std::cout << median3(A,0,4) << std::endl;
    //InsetSort(A,5);
    Qsort(A,0,4);
    for(int l=0; l < 5; l++)
        std::cout << A[l] << " ";
    std::cout<<std::endl;
}

#include<iostream>     //include<>的查找位置是标准库头文件所在目录，
#include"ShellSort.h"  //include""先从当前目录查找，若找不到再从标准库所在目录

int* ShellSort(int A[], int N)
{
    int temp;

    for(int d = N/2; d > 0; d/=2)
    {
        int i = d;
        while(i < N) //这里不能只循环一遍 需要一直循环知道对应间隔都满足小于关系
        {
            if(A[i] < A[ i-d ])
            {
                temp = A[ i-d ];
                A[ i-d ] = A[i];
                A[i] = temp;
                i = d;
            }
            else
            {
                i++;
            } 
        }
        for(int j = 0;j < N;j++)
            std::cout << A[j] <<" ";
        std::cout<<std::endl;
    }

    return A;
}

int main()
{
    int A[30] = {1,9,2,10,3,11,4,12,5,13,6,14,7,15,8,16,99,0,1,9,2,10,3,12,5,6,7,7,2,2};
    int *b = ShellSort(A,30);
    for(int i = 0;i < 30;i++)
        std::cout << b[i] <<" ";
    std::cout<<std::endl;
    return 0;
}

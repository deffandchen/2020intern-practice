#include<iostream>
#include<malloc.h>

using namespace std;
/*
合并两个数组，l_pos左边开始位置，rpos右边开始位置，rend右边结束位置
*/
void merge(int a[],int tmp[],int l_pos,int r_pos,int r_end)
{
    int l_end,tmp_pos,cnt;
    l_end = r_pos - 1;
    tmp_pos = l_pos;
    cnt = r_end - l_pos + 1;
    while(l_pos<=l_end && r_pos <= r_end)
    {
        if(a[l_pos] <= a[r_pos]) tmp[tmp_pos++] = a[l_pos++];
        else tmp[tmp_pos++] = a[r_pos++]; 
    }
    while(l_pos <= l_end) tmp[tmp_pos++] = a[l_pos++];
    while(r_pos <= r_end) tmp[tmp_pos++] = a[r_pos++];

    for(int i=0;i<cnt;i++,r_end--)
        a[r_end] = tmp[r_end];
}

void mergeSort(int a[],int tmp[],int left,int right)
{
    int mid = (left + right) / 2;
    if(left<right)
    {
        mergeSort(a,tmp,left,mid);
        mergeSort(a,tmp,mid+1,right);
        merge(a,tmp,left,mid+1,right); //借用一个辅助数组进行融合
    }
}

int main()
{
    int a[9] = {1,3,5,2,7,5,0,3,4};
    int* tmp = (int*)malloc(9*sizeof(int));
    mergeSort(a,tmp,0,8);
    free(tmp);
    return 0;
}
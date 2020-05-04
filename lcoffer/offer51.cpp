#include<iostream>
#include<vector>
using namespace std;
int res=0;
void merge(vector<int>& nums,vector<int>& tmp,int left,int mid,int right)
{
    int right_s = mid + 1;
    int left_s = left;
    int tmp_s = left_s;
    int right_e = right;
    while(left_s <= mid && right_s <= right)
    {
        if(nums[left_s] <= nums[right_s])
            tmp[tmp_s++] = nums[left_s++];
        else
        {
            tmp[tmp_s++] = nums[right_s++];
            res += mid - left_s+1;
        }
    }
    while(left_s<=mid) 
    {
        tmp[tmp_s++] = nums[left_s++];
    }
    while(right_s<=right) tmp[tmp_s++] = nums[right_s++];
    for(int i = right;i>=left;i--)
        nums[i] = tmp[i];
}

void msort(vector<int>& nums,vector<int>& tmp,int left,int right)
{
    int mid = (left + right)/2;
    if(left < right)
    {
        msort(nums,tmp,left,mid);
        msort(nums,tmp,mid+1,right);
        merge(nums,tmp,left,mid,right);
    }
}

void mergeSort(vector<int>& nums)
{
    int len = nums.size();
    vector<int> tmp(len,0);
    msort(nums,tmp,0,len-1);
}

int main()
{
    vector<int> a = {7,5,6,4};
    mergeSort(a);
    cout<< res << endl;
    return 0;
}
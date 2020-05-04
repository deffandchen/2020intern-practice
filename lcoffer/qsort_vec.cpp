#include<iostream>
#include<vector>

using namespace std;

int mediate(int left,int right,vector<int>& nums)
{
    int mid = (left + right) / 2;
    if(nums[left] > nums[right])
        swap(nums[left],nums[right]);
    if(nums[left] > nums[mid])
        swap(nums[left],nums[mid]);
    if(nums[mid] > nums[right])
        swap(nums[mid],nums[right]);
    
    swap(nums[mid],nums[right-1]);

    return nums[right-1];
}

void qsort(int left,int right,vector<int>& nums)
{
    if(left + 1 < right)
    {
        int center = mediate(left,right,nums);
        int i = left,j = right - 1;
        for(;;)
        {
            while(nums[++i] < center) {}
            while(nums[--j] > center) {}
            if(i<j)
                swap(nums[i],nums[j]);
            else
                break; 
        }
        swap(nums[i],nums[right-1]);
        qsort(left,i-1,nums);
        qsort(i+1,right,nums);
    }
    else
    {
        if((right - left == 1) && (nums[left] > nums[right]))
        {
            swap(nums[left],nums[right]);
        }
        return ;
    }  
}

vector<int> sortArray(vector<int>& nums) {
    int len = nums.size();
    qsort(0,len-1,nums);
    return nums;
}

int main()
{
    vector<int> nums = {5,4,3,2,1,1,2,3,4,5,60,7,0,9,1,34,46,23,578,231,7,80,2};
    sortArray(nums);

    for(auto n:nums)
    {
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int thirdMax(vector<int>& nums) {
    int a=LONG_MIN,b=LONG_MIN,c=LONG_MIN;
    int cnt=0;
    for(int i = 0;i<nums.size();i++)
    {
        if(nums[i]>c)
        {
            a = b;
            b = c;
            c = nums[i];
            cnt++;
        }
        else if(nums[i]>b && nums[i]<c)
        {
            a = b;
            b = nums[i];
            cnt++;
        }
        else if(nums[i]>a && nums[i]<b)
        {
            a = nums[i];
            cnt++;
        }
    }
    if(cnt>=3) return a;
    else return c;
}

int main()
{
    vector<int> nums = {1,2,2,5,3,5};
    thirdMax(nums);
    return 0;
}
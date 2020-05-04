#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isStraight(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int cnt = 0;
    for(int i=0;i<5;i++)
    {
        if(nums[i]==0) cnt++;
        else break;
    }
    for(int i= cnt+1;i<5;i++)
    {
        if(nums[i] == nums[i-1]+1) 
            continue;
        else
        {
            int cha = nums[i] - nums[i-1];
            if((cha-1)>cnt) return false;
            else
                cnt = cnt -cha;
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {0,0,2,2,5};
    isStraight(nums);
    return 0;
}
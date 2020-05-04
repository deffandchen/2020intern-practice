#include<bits/stdc++.h>

using namespace std;

int jump(vector<int>& nums) {
    //如果下次跳不能到终点 那就找个最大的跳
    int len = nums.size();
    vector<int> dp(len,0);
    int res = 0;
    for(int i=0;i<len-1;i++)
    {
        int tmp = nums[i];
        while(tmp)
        {
            int idx = tmp+i;
            tmp--;
            if(idx>= len-1)
            {
                res = dp[i]+1;
                return res;
            }      
            else
            {
                if(dp[idx]==0) 
                    dp[idx] = dp[i]+1;
                else
                    break;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {2,3,1,1,4};
    jump(nums);
    return 0;
}
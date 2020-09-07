#include<bits/stdc++.h>

using namespace std;

int GetMaxConsecutiveOnes(vector<int>& arr, int k) {
    // write code here
    int sz = arr.size();
    int cnt = 0;
    int len = 0;
    vector<vector<int>> dp(sz,vector<int>(sz,0));
    for(int i=0;i<sz;i++)
    {
        for(int j=i;j<sz;j++)
        {
            if(arr[j] == 0)
            {
                dp[i][j] = dp[i][j-1] + 1;
            }
            else
            {
                if(j==0)
                    dp[i][j] = 0;
                else
                dp[i][j] = dp[i][j-1];
            }
            if(dp[i][j]<=k)
                len = max(len,j-i+1);
        }
    }     
}

int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    GetMaxConsecutiveOnes(nums,2);
    return 0;
}
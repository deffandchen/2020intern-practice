#include<bits/stdc++.h>

using namespace std;
//以i和j结尾 那么找到k在不在，k在的话就加上k的
int longestFeb(vector<int> &nums)
{
    int len = nums.size();
    map<int,int> dat;
    for(int i=0;i<len;i++)
    {
        dat[nums[i]] = i;
    }

    vector<int,int> dp;
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++)
        {
            if(dat.count(nums[j]-nums[i]))
            {
                int idx = dat[nums[j]-nums[i]];
            }
        }
}
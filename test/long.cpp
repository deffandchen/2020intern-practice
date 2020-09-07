#include<bits/stdc++.h>

using namespace std;

vector<int> longest(vector<int>& nums)
{
    vector<int> res;
    vector<int> tmp;
    int max_len = 0;
    for(int i=0;i<nums.size();i++)
    {
        tmp.clear();
        tmp.push_back(nums[i]);
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j] > tmp[tmp.size()-1])
            {
                tmp.push_back(nums[j]);
            }
        }
        if(tmp.size()>res.size())
            res = tmp;
    }
    return res;
}

int main()
{
    return 0;
}
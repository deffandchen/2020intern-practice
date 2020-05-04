#include<bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> dict;
    int longst = 0;
    for(int i=0;i<nums.size();i++)
    {
        dict[nums[i]] = 1;
    }
    for(auto d:dict)
    {
        int tmp = d.first - 1;
        int cnt = 1;
        while(dict[tmp])
        {
            cnt+=dict[tmp];  
            dict[tmp] = 0;
            tmp--;    
            dict[d.first] = cnt;
        }
        longst = max(longst,cnt);
    }
    return longst;
}

int main()
{
    vector<int> nums = {1,3,5,2,4};
    longestConsecutive(nums);
    return 0;
}
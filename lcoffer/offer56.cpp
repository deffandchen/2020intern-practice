#include<bits/stdc++.h>
using namespace std;
vector<int> singleNumbers(vector<int>& nums) {
    int s = 0,cnt=0;
    for(int i=0;i<nums.size();i++)
    {
        s = s^nums[i];
    }
    while(s)
    {
        if(s&1==1) break;
        cnt++;
        s=s>>1; 
    }
    vector<int> nums1,nums2;
    for(int i=0;i<nums.size();i++)
    {
        int tmp = cnt;
        int val = nums[i];
        while(tmp--)
        {
            val = val>>1;
        }
        if(val&1==1) nums1.push_back(nums[i]);
        else nums2.push_back(nums[i]);
    }
    int s1=0,s2=0;
    for(int i=0;i<nums1.size();i++)
    {
        s1 ^= nums1[i];
    }
    for(int i=0;i<nums2.size();i++)
        s2 ^= nums2[i];
    vector<int> ans;
    ans.push_back(s1);
    ans.push_back(s2);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,5,2};
    singleNumbers(nums);
    return 0;
}
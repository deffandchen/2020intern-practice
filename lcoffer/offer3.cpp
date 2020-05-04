#include<iostream>
#include<vector>

using namespace std;
vector<int> nums;
vector<int> ans;
void dfs(int left,int right)
{
    int rep_cnt = (right - left) / 2 ;
    if(rep_cnt == 0)
    {
        ans.push_back(left);
        ans.push_back(right);
        return ;
    }
    int mid = (left + right) / 2;
    int cnt = 0; 
    int cha = mid - left;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] >= left && nums[i] < mid)
            cnt++;
    }
    if(cnt > cha)
        dfs(left,mid);
    else
        dfs(mid,right);
}

void dfs1(int left,int right)
{
    int rep_cnt = (right - left) / 2 ;
    if(rep_cnt == 0)
    {
        ans.push_back(left);
        ans.push_back(right);
        return ;
    }
    int mid = (left + right) / 2;
    int cnt = 0; 
    int cha = mid - left;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] >= left && nums[i] < mid)
            cnt++;
    }
    if(cnt > mid)
        dfs(left,mid);
    else
        dfs(mid,right);
}

int main()
{
    vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 1}; //n为9 元素大小在0-n内
    nums = num;
    int len = nums.size();
    vector<int> tmp;
    dfs(1,len);
    tmp = ans;
    return 0;
}
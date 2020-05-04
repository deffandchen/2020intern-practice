#include<iostream>
#include<vector>
#include<stack>
#include<set>

using namespace std;
vector<vector<int>> ans;
vector<int> nums;
stack<int> path;

void dfs(int target,int idx)  //每次输入减后的值，和下一个需要找的元素的位置
{
    if(target == 0)
    {
        vector<int> tmp;
        while(!path.empty())
        {
            tmp.push_back(path.top());
            path.pop();
        }
        for(int i=tmp.size()-1;i>=0;i--)
        {
            path.push(tmp[i]);
        }
        ans.push_back(tmp);
        return ;
    }
    else
    {
        if(target < 0)
        {
            //path.pop();
            return ;
        }
        else
        {
           for(int i = idx;i<nums.size();i++)
           {
               int cha = target - nums[i];
               path.push(nums[i]);
               dfs(cha,i);
               path.pop();
           } 
        }   
    }
}

int main()
{
    vector<int> dat = {2,3,5};
    int target = 8;
    nums = dat;
    dfs(target,0);
    vector<vector<int>> vec; 
    vec = ans;

    return 0;
}
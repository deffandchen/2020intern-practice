#include<iostream>
#include<vector>

using namespace std;
vector<int> one = {1,2,3,4,5,6};
vector<int> dfs(int n)
{
    if(n==1) return one;
    else if(n%2==0)
    {
        vector<int> tmp = dfs(n/2);
        vector<int> res;
        for(int i=0;i<tmp.size();i++)
            for(int j=0;j<tmp.size();j++)
            {
                res.push_back(tmp[i]+tmp[j]);
            }
        return res;
    }
    else
    {
        vector<int> tmp = dfs(n-1);
        vector<int> res;
        for(int i=0;i<one.size();i++)
            for(int j=0;j<tmp.size();j++)
            {
                res.push_back(tmp[i]+tmp[j]);
            }
        return res;
    }
    return vector<int>{};
}

int main()
{
    vector<int> ans;
    ans = dfs(11);
    for(auto an:ans) cout << an << ' ';
    cout << endl;
    return 0;
}
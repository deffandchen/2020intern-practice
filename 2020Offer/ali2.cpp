#include<bits/stdc++.h>

using namespace std;
using ll = long long; 
int n;
int m;
string str;
vector<vector<char>> vec;

void dfs(int idx,vector<char>& path)
{
    if(idx == str.size())
    {
        vec.push_back(path);
        return;
    }
    
    for(int i=idx;i<str.size();i++)
    {
        swap(str[i],str[idx]);
        path.push_back(str[idx]);
        dfs(idx+1,path);
        swap(str[i],str[idx]);
        path.pop_back();
    }
}
int main()
{
    cin >> n >> m;
    str = to_string(n);
    vector<char> pat;
    dfs(0,pat);
    int res =0;
    for(auto v:vec)
    {
        string num;
        
        for(int j=0;j<v.size();j++)
        {
            num += v[j];
        }
        
        int cnt = stoi(num);
        if(cnt%m == 0)
            res++;
    }
    cout << res << endl;
    return 0;
}
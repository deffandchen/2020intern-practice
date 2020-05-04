#include<bits/stdc++.h>

using namespace std;
int max_val = 0;
void dfs(vector<vector<int>> dat,int start,int sum)
{
    sum += dat[start-1][1];
    if(dat[start-1].size()==2)
    {
        max_val = max(max_val,sum);
        return ;
    }
    for(int i=2;i<dat[start-1].size();i++)
    {
        if(dat[start-1][i] <= start)
        {
            max_val = INT_MAX;
            return;
        }
        dfs(dat,dat[start-1][i],sum);
    }
}
int main()
{
    vector<vector<int>> dat;
    int n;
    cin >> n;
    vector<int> grp;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        grp.push_back(tmp);
    }
    for(int i=1;i<=n;i++)
    {
        vector<int> vtmp;
        for(int j=0;j<grp[i-1]+2;j++)
        {
            int tmp;
            cin >> tmp;
            vtmp.push_back(tmp);   
        }
        dat.push_back(vtmp);
    }
    dfs(dat,1,0);
    if(max_val<INT_MAX)
        cout << max_val << endl;
    else
    {
        cout << 'R'<<endl;
    }
    
    return 0;
}
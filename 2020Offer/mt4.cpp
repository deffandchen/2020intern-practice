#include<bits/stdc++.h>
using namespace std;
int n,a,b;
vector<vector<int>> dat;
int res=0;
void dfs(int idx,int anum,int asum,int bnum,int bsum)
{
    if(idx>=n) return ;
    if(anum < a && bnum < b)
    {
        dfs(idx+1,anum+1,asum+dat[idx][0],bnum,bsum);
        dfs(idx+1,anum,asum,bnum+1,bsum+dat[idx][1]);
        dfs(idx+1,anum,asum,bnum,bsum);
    }
    else if(anum>=a && bnum<b)
    {
        dfs(idx+1,anum,asum,bnum+1,bsum+dat[idx][1]);
        dfs(idx+1,anum,asum,bnum,bsum);
    }
    else if(bnum>=b && anum < a)
    {
        dfs(idx+1,anum+1,asum+dat[idx][0],bnum,bsum);
        dfs(idx+1,anum,asum,bnum,bsum);
    }
    else if(bnum>=b && anum>=a)
    {
        res = max(res,asum+bsum);
    }
}

int main()
{

    cin >> n >> a >> b;
    int apfit,bpfit;
    vector<vector<int>> data(n,vector<int>(2,0));

    for(int i=0;i<n;i++)
    {
        cin >> apfit >> bpfit;
        data[i][0] = apfit;
        data[i][1] = bpfit;
    }
    dat = data;
    dfs(0,0,0,0,0);
    cout << res << endl;
}
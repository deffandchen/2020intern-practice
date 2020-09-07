#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> dat;
int N,M,total = 0;
void dfs(vector<vector<bool>> flag,int row,int col){
    if(row>N)
    {
        total++;
        total = total % 100000000;
        return;
    }
    if(col>M)
    {
        row++;
        col = 1;
        dfs(flag,row,col);
    }
    else
    {

            if(dat[row][col] != 0 && flag[row-1][col]==false && flag[row][col-1]==false)
            {
                flag[row][col] = true;
                dfs(flag,row,col+2);
            }
        
            flag[row][col] = false;
            dfs(flag,row,col+1);
    
    }
}

int main()
{
    int n,m,in;
    cin >> n >> m;
    N = n;
    M = m;
    vector<vector<int>> dat_init(n+1,vector<int>(m+1,0));
    dat = dat_init;
    vector<vector<bool>> flag(n+1,vector<bool>(m+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> in;
            dat[i][j] = in;
        }
    }
    dfs(flag,1,1);
    cout << total << endl;
    return 0;
}
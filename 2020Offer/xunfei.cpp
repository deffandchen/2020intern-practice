#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,tmp;
    string str;
    cin >> str;
    m = str[0] - '0';
    n = str[2] - '0';
    vector<vector<int>> dat(m+1,vector<int>(n+1,0));
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        {
            cin >> tmp;
            dat[i][j] = tmp;
        }
    
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + dat[i][j];
        }
    cout << dp[m][n] << endl;
    return 0;
}
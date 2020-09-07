#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,tmp1,tmp2;
    cin >> n >> m;
    vector<int> v(n,0);
    vector<int> w(n,0);
    for(int i=0;i<n;i++)
    {
        cin >> tmp1 >> tmp2;
        v[i] = tmp1;
        w[i] = tmp2;
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++)
        {
            if(j>=v[i])
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
        }
    cout << dp[n][m] << endl;
    return 0;
}
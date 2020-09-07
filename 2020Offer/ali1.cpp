#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n,v;
    cin >> n >> v;
    vector<vector<int>> dat(n,vector<int>(2,0));
    
    for(int i=0;i<n;i++)
    {
        cin >> dat[i][0] >> dat[i][1];        
    }
    vector<vector<int>> dp(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=v;j++)
        {
            if(dat[i][0] <= j) 
                dp[j] = max(dp[j],dp[j-dat[i][0]]+dat[i][1]);
        }
    }
    cout << dp[v] << endl;
    return 0;
}
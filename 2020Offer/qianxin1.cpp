#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int res = 0;
    cin >> n;
    if(n<0 || n>36)
    {
        cout << res << endl;
        return 0;
    }
    vector<int> dp(n+1,0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;
    return 0;
}
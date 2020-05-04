#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;

    int a_len = a.size();
    int b_len = b.size();
    vector<vector<int>> dp(a_len+1,vector<int>(b_len+1,0));

    for(int i=1;i<=a_len;i++)
    {
        for(int j=1;j<=b_len;j++)
        {
            if(a[i-1] != b[j-1])
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j-1] + 1;

        }
    }
    cout << dp[a_len][b_len] << endl;

    return 0;
}
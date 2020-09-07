#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char tmp;
    cin >> n;
    vector<vector<char>> dat(2,vector<char>(n,'0'));
    for(int j=0;j<2;j++)
        for(int i=0;i<n;i++)
    {
        cin >> tmp;
        dat[j][i] = tmp;
    }
    vector<vector<int>> dp(2,vector<int>(n,0));
    for(int j=0;j<n;j++)
        for(int i=0;i<2;i++)
        {
            if(dat[i][j] == 'x')
                continue;
            else if(dat[i][j] == '.')
            {
                if(i==0 && j==0) dp[i][j] = 1;
                else if(i == 0 && j>0) dp[i][j] = dp[i][j-1] + dp[i+1][j-1];
                else if(i==1 && j>0) dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
        }
    return dp[1][n-1];
}
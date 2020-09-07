#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    int start = 0,end = 0,max_len = 0;
    vector<vector<int>> res;
    for(int i=n-1;i>=0;i--)
    {
        for(int j = i;j<n;j++)
        {
            if(j == i) dp[i][j] = true;
            else if(j == i+1)
            {
                dp[i][j] = s[i]==s[j]; 
                //if(s[i]==s[j])
                //    dp[i][j] = true;
            }
            else
            {
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
                //    dp[i][j] = true;
            }
            
            if(dp[i][j] && max_len<j-i+1)
            {
                vector<int> tmp;
                start = i;
                end = j;
                tmp.push_back(i);
                tmp.push_back(j);
                res.clear();
                res.push_back(tmp);
                max_len = j - i + 1;
            }
            else if(dp[i][j] && max_len==j-i+1)
            {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                res.push_back(tmp);
                max_len = j - i + 1;
            }
        }
    }
    if(start == end)
        cout << "null" << endl;
    else
    {
        for(int i=0;i<res.size();i++)
        {
            start = res[i][0];
            end = res[i][1];
            cout << s.substr(start,end+1) << endl;
        }
    }
        
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

void longest(string s){
    int len = s.size();
    if(len <= 1){
        cout << s <<endl;
        return;
    }
    bool dp[1001][1001];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<len;i++){
        dp[i][i] = true;
        dp[i][i-1] = true;
    }
    int left=0,right=0,max = 0;
    for(int k=2;k<=len;k++){
        for(int i=0;i<len-k+1;i++)
        {
            if(s[i]==s[k-1+i] && dp[i+1][k+i-2])
            {
                dp[i][k-1+i] = true;
                if(max < k-1)
                {
                    max = k-1;
                    left = i;
                    right = k-1+i;
                }
            }
        }
    }
    string res = s;
    if(right == s.size()-1)
    {
        int i = left;
        while (i>0)
        {
            i--;
            res += s[i]; 
        }
    }
    else
    {
        int i = s.size()-1;
        while (i>0)
        {
            i--;
            res+=s[i];
        }
    }

    cout << res << endl;
}

int main()
{
    string s;
    cin >> s;
    longest(s);
    return 0;
}
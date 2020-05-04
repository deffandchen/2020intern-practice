/*
阿里3.27笔试
要求：将字符串s1转换为s2,
转换规则：每次可以将s1中的任意一个字符移动到s1的末尾
目的：求最少的改变次数时，s1转换为s2
比如

输入：
acdk
ckad
输出：
2

*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;

    int len1 = s1.size();
    int len2 = s2.size();

    if(len1 != len2)
        cout << 0 << endl;
    else
    {
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        int longsub = dp[len1][len2];
        int ans = len1 - longsub;
        cout << ans << endl;
    }
    
    return 0;
}
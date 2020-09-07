#include<bits/stdc++.h>

using namespace std;

int N,M;
vector<int> dat;

int main()
{
    cin >> N >> M;
    int tmp;
    for(int i=0;i<N;i++)
    {
        cin >> tmp;
        dat.emplace_back(tmp);
    }
    vector<long long> dp(M+1,-1);
    dp[0] = 1;
    for(int i=1;i<M+1;i++)
    {
        long long idx = 0;
        for(int j=0;j<dat.size();j++)
        {
            if(i>=dat[j])
                idx += dp[i-dat[j]];
        }
        dp[i] = idx % 10000000007;
    }
    
    cout << dp[M] << endl;
    return 0;
}
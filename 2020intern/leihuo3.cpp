#include<bits/stdc++.h>

using namespace std;
int N,S,X;
int ans=0,tmp; 
void dfs(int idx,int mul,int sum)
{
    if(idx>=3)
    {
        if(mul%X!=0)
            return ;
    }
    if(sum > S) 
        return;
    if(idx>=N) 
    {
        if(sum == S)
        {
            ans = (ans+1) % 1000009;
        }
        return ;
    }
    for(int i=0;i<10;i++)
    {
        tmp = (mul%100)*10 + i;
        dfs(idx+1,tmp,sum+i);
    }
}

int main()
{
    cin >> N >> S >> X;
    dfs(0,0,0);
    cout << ans << endl;
    return 0;
}
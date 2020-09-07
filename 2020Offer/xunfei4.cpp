#include<bits/stdc++.h>
//分解质因数
using namespace std;

int N;

void dfs(int idx,int n)
{
    if(n < 2) return;
    for(int i=2;i<=idx;i++)5
    {
        if(n%i == 0)
        {
            if(n/i == 1)
                printf("%d",i);
            else 
                printf("%d*",i);
            dfs(idx,n/i);
            break;
        }
    }
}
int main()
{
    cin >> N;
    dfs(N,N);
    return 0;
}
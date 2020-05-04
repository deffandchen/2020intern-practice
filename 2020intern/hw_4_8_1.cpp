/*************************************
题目：输入N,M，求N+N^2+N^3+...+N^M的结果（取余1000000007），1<N<=65536，1<M<=100000

输入格式：每行输入N M，直到N M均等于0时跳出
输出格式：每行输出对应的结果
**************************************/

#include<bits/stdc++.h>
using namespace std;

long long q_pow(int n,int m)
{
    long long ans = 1,base = n;
    while(m)
    {
        if(m&1) ans = ans * base % 1000000007;
        base = base * base % 1000000007;
        m>>=1;
    }
    return ans;
}

int main()
{
    int n,m;   //快速幂
    cout << q_pow(65535,100000) << endl;
    while (cin>>n>>m)
    {
        if(n==0 && m==0) break;
        int ans = 0;
        for(int i=1;i<=m;i++)
        {
            ans += q_pow(n,m) % 1000000007;
        }
        /*
        int last = 1;
        int ans = 0;
        for(int i=1;i<=m;i++)
        {
            ans += last * n % 1000000007;
            last = last * n % 1000000007;
        }
        */
        cout << ans << endl;
    }
    return 0;
}
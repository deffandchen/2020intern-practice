#include<iostream>

using namespace std;

int pow(int n)
{
    int ans = 1;
    while (n)
    {
        ans = ans * n % 1000000007;
        n = n-1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int nn = pow(n);
    long res = 0;
    for(int i=1;i<=n;i++)
    {
        res += i * nn/(pow(i) * pow(n-i)) % 1000000007;
    }
    cout << res << endl;
    return 0;
}
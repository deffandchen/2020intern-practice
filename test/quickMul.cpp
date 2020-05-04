#include<iostream>

using namespace std;

long long quickMul(int a,int n){
    long long ans = 1;
    long long base = a;
    while(n>0)
    {
        if(n&1) ans *= base;
        base *= base;
        n /= 2;
    }
    return ans;
}

int main()
{
    int a = 5,n = 10;
    cout << quickMul(a,n) << endl;
    return 0;
}
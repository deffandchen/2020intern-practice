#include<iostream>
#include<map>
#include<vector>

using namespace std;

int calc(int n)
{
    int ans=0;
    while(n)
    {
        if(n%10 == 1)
            ans += 1;
        n /= 10;
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;
    //map<int,int> res;
    vector<int> res(N,0);
    res[1] = 1;

    int i=10,ans=1;
    while(i<=N)
    {
        res[i] = res[i/10] + res[i%10];
        ans += res[i];
        i++;
    }

    cout << ans << endl;
    return 0;
}
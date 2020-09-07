#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,tmp,max_high = INT_MIN;
    cin >> n;
    vector<int> dat(n,0);
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        dat[i] = tmp;
        max_high = max(max_high,tmp);
    }
    int res = 0;
    bool flag = false;
    for(int i = 1;i<=max_high;i++)
    {
        flag = true;
        for(int j=0;j<dat.size();j++)
        {
            if(dat[j] == 0)
            {
                flag = true;
                continue;
            }   
            if(dat[j]>0 && flag)
            {
                res++;
                flag = false;
            }
            dat[j]--;
        }
    }
    res = max(res,n);
    cout << res << endl;
    return 0;
}
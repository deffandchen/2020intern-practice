#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,tmp;
    cin >> n >> m;
    vector<int> b(m,0);
    unordered_set<int> key;
    for(int i=0;i<m;i++)
    {
        cin >> tmp;
        b[i] = tmp;
    }
    unique(b.begin(),b.end());
    int res = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i%b[j] == 0)
            {
                res++;
                key.insert(i);
                break;
            }            
        }
    }
    cout << res << endl;
    return 0;
}
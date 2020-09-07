#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    map<int,set<int>> renke;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        if(x!=y)
        {
            renke[x].insert(y);
        }
    }
    for(auto r:renke)
    {
        for(auto se:r.second)
        {
            if(renke.count(se))
            {
                for(auto s:renke[se])
                {
                    renke[r.first].insert(s);
                }
            }
        }
    }
    int ret = 0;
    for(auto r:renke)
    {
        for(auto se:r.second)
        {
            if(renke.count(se))
            {
                for(auto s:renke[se])
                {
                    if(s == r.first){
                        ret++;
                    }
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}
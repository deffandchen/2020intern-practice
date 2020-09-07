#include<bits/stdc++.h>

using namespace std;
static bool cmp(pair<int,int>& a,pair<int,int>& b)
{
    if(a.first <= b.first)
        return true;
    else 
        return false;
}

int main()
{
    int t,n,m,tmp;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n >> m;
        vector<pair<int,int>> val;
        vector<pair<int,int>> rest;
        for(int j=0;j<n;j++){
            cin >> tmp;
            val.push_back({tmp,j});
        }
        for(int j=0;j<m;j++){
            cin >> tmp;
            rest.push_back({tmp,j});
        }
        sort(val.begin(),val.end(),cmp);
        sort(rest.begin(),rest.end(),cmp);
        
        vector<int> res(n,-1);
        int idx = 0;
        for(int k=0;k<n;++k)
        {
            while(idx < m && rest[idx].first < val[k].first) 
                ++idx;
            if(idx == m) 
                break;
            res[val[k].second] = rest[idx].second + 1;
            ++idx;
        }
        for(int id = 0;id<n;++id)
        {
            cout << res[id] << ' ';
        }
    }
    return 0;
}
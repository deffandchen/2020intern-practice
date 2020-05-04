#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<vector<int>,int> dat;
    int N;
    cin >> N;
    int pos,ans=0;
    
    for(int i=0;i<N;i++)
    {
        vector<int> in;
        for(int j=0;j<3;j++)
        {
            cin >> pos;
            in.push_back(pos);
        }
        dat[in] = 1;
    }
    for(auto d:dat)
    {
        for(int i=0;i<d.first.size();i++)
        {
            cout << d.first[i] << ' ';
        }
    }
    for(auto d:dat)
    {
        vector<int> tmp = d.first;
        int jiechu = 0;
        for(int j=0;j<3;j++)
        {
            tmp[j] = tmp[j]+1;
            if(dat.find(tmp)!=dat.end())
            {
                jiechu++;
            }
            tmp[j] = tmp[j]-2;
            if(dat.find(tmp)!=dat.end())
            {
                jiechu++;
            }
            tmp[j] = tmp[j]+1;
        }
        ans += 6-jiechu;
    }
    cout << ans << endl;
    return 0;
}
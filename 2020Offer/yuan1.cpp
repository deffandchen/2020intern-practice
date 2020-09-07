#include<bits/stdc++.h>

using namespace std;

vector<int> res;
int n;
vector<int> data;
void dfsl(int idx)
{
    if(idx <=n)
    {
        res.push_back(data[idx]);
        dfsl(idx*2);
        if((idx+1) <= n)
        {
            if((idx+1)*2 <= n)
                dfsl((idx+1)*2);
            else
               res.push_back(data[idx+1]);           
        }
    }
}
void dfsr(int idx)
{
    if((2*idx+1)<=n)
    {
        dfsr(idx*2+1);
        res.push_back(data[idx]);
    }
}
int main()
{
    int tmp;
    cin >> n;
    vector<int> dat(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> tmp;
        dat[i] = tmp;
    }
    data = dat;
    res.push_back(dat[1]);
    dfsl(2);
    dfsr(3);
    for(int i=0;i<res.size()-1;i++)
    {
        cout << res[i] << " ";
    }
    cout << res[res.size()-1] << endl;
    return 0;
}
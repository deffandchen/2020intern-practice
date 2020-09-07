#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,tmp;
    cin >> n >> k;
    vector<int> dat;
    for(int i=0;i<n-1;i++)
    {
        cin >> tmp;
        if(i == k-1)
            continue;
        dat.push_back(tmp);
        //cout << tmp;
    }
    for(int i=0;i<dat.size()-1;i++)
    {
        cout << dat[i] << ' ' ;
    }
    cout << dat[dat.size()-1] <<endl;
    return 0;
}
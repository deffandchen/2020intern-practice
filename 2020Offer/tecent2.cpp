#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int k;
    getline(cin,s);
    cin >> k;
    set<string> dat;
    
    for(int i=1;i<=s.size();i++)
    {
        for(int j=0;j<s.size()-i+1;j++)
        {
            string tmp = s.substr(j,i);
            dat.insert(tmp);
        }
    }
    int idx=0;
    for(auto d:dat)
    {
        if(idx == k-1)
        {
            cout << d << endl;
            break;
        }
        idx++;
    }
    return 0;
}
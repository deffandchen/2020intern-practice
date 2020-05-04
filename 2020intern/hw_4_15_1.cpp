#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string,int> dat;
    string s;
    getline(cin,s);
    int start = 0;
    string name;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==',')
        {
            name = s.substr(start,i-start);
            dat[name]++;
            start = i+1;
        }
        else if(i==s.size()-1)
        {
            name = s.substr(start,i-start+1);
            dat[name]++;
            start = i+1;
        }
        for(int j =0;j<name.size();j++)
        {
            if(j==0)
            {
                if(name[j]<'A' || name[j]>'Z')
                {
                    cout << "error.0001" << endl;
                    return 0;
                }
            }
            else
            {
                if(name[j]<'a' || name[j]>'z')
                {
                    cout << "error.0001" << endl;
                    return 0;
                }
            }
        }
    }
    string ans;
    int max = 0;
    for(auto d:dat)
    {
        if(d.second > max)
        {
            max = d.second;
            ans = d.first;
        }
    }
    cout << ans << endl;
    return 0;
}
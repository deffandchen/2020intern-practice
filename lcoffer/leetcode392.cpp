#include<iostream>
using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    int j=0;
    for(int i=0;i<t.size();i++)
    {
        if(t[i] == s[j])
            j++;
        if(j==s.size())
        {
            break;
        }
    }
    if(j==s.size())
        cout << "true" << endl;
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
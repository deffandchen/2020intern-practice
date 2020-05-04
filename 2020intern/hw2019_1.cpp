#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
    string s,out_str;
    cin >> s;
    set<char> tmp;
    for(char i:s)
    {
        if(tmp.find(i) == tmp.end())
        {
            tmp.insert(i);
            out_str.push_back(i);
        }
    }
    cout << out_str << endl;
    return 0;
}
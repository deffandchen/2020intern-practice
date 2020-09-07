#include<bits/stdc++.h>

using namespace std;

int main()
{
    int dat;
    vector<int> vec;
    map<int,int> m;
    cin >> dat;
    cout << dat;
    m[dat] = 1;
    while(cin >> dat)
    {
        if(m.find(dat)==m.end())
        {
            m[dat] = 1;
            cout << ' ' << dat;
        }
    }
    cout << endl;
    return 0;
}
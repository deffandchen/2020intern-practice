#include<bits/stdc++.h>

using namespace std;

int n;



int main()
{
    cin >> n;
    string str = to_string(n);
    reverse(str.begin(),str.end());
    int rver = stoi(str);
    long res=0;
    vector<int> vec;
    int yu,chu;
    while(rver)
    {
        yu = rver % 5;
        rver = rver / 5;
        vec.push_back(yu);
    }
    for(int i = 0;i<vec.size();i++)
    {
        res += vec[i]*pow(10,i);
    }
    cout << res << endl;
    return 0;
}
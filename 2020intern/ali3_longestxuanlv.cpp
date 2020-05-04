#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    string in;
    cin >> n;
    
    vector<string> dat;

    for(int i=0;i<n;i++)
    {
        cin >> in;
        dat.push_back(in);
    }

    sort(dat.begin(),dat.end());
    vector<int> dp(n,0);
    for(int i=0;i<n;i++)
    {
        
    }
}
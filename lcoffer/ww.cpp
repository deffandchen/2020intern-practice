#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> pos;
vector<int> supply;
int d,w;
int main()
{
    int i;
    cin >> d >> w;
    while(cin>>i)
    {
        pos.push_back(i);
    }
    while(cin>>i)
    {
        supply.push_back(i);
    }
    sort(supply.begin(),supply.end());
    int len = supply.size();
    if(supply[len-1] >= (d-w))
        cout << 1 << endl;
    return 0;
}
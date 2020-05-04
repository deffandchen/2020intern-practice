#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> dat(8,vector<int>{0,0});
int main()
{
    int i,j;
    while(1)
    {
        cin >> i >> j;
        if(i==-1 && j==-1)
            break;
        dat[i-12][0]++;
        dat[j-13][1]++;
    }
    vector<int> cnt(8,0);
    cnt[0] = dat[0][0];
    cout << "[12,13):"<< cnt[0] << endl;
    for(i=1;i<8;i++)
    {
        cnt[i] = dat[i][0] + cnt[i-1] - dat[i-1][1];
        cout << "["<<i+12<<','<<i+13 << "):" << cnt[i] << endl;
    }
    return 0;
}
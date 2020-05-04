#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N,i=0,in;
    cin >> N;
    vector<vector<int>> dat(2,vector<int>{});
    while(i<N)
    {
        i++;
        cin >> in;
        dat[0].push_back(in);
    }
    i=0;
    while(i<N)
    {
        i++;
        cin >> in;
        dat[1].push_back(in);
    }
    sort(dat[0].begin(),dat[0].end());
    sort(dat[1].begin(),dat[1].end());
    int a = dat[0][N-1] + dat[0][N-2] + dat[0][N-3];
    int b = dat[1][N-1] + dat[1][N-2] + dat[1][N-3];
    if(a>=b) cout << a << endl;
    else cout << b << endl;
    return 0;
}
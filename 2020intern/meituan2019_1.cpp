#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int n=N;
    string in;
    vector<string> dat;
    while(n--)
    {
        cin >> in;
        dat.push_back(in);
    }
    int a,b,cnt=0;
    cin >> a >> b;
    int size = dat[a-1].size()>dat[b-1].size()?dat[b-1].size():dat[a-1].size();
    for(int i=0;i<size;i++)
    {
        if(dat[a-1][i] == dat[b-1][i])
        {
            cnt++;
        }
        else
            break;
    }
    cout << cnt << endl;
    return 0;
}
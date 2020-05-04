#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string dat;
    int N,k,i;
    cin >> N >> k;
    int n = N,max=0;
    while(n--)
    { 
        cin >> i;
        dat += to_string(i);
    }
    for(int i=0;i<N-k;i++)
    {
        for(int j=N-1;j>i+k;j--)
        {
            int cnt = count(dat.begin()+i,dat.begin()+j,'0');
            if(cnt <= k)
            {
                max = j-i >max ? j-i:max;
                break;
            }
        }
    }
    cout << max << endl;
}
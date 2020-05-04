#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,s=0;
    cin >> N;
    vector<int> hi(N,0);
    for(int i=0;i<N;i++)
    {
        cin >> hi[i];
    }
    int min_idx=0,peek; 
    stack<int> sck;
    sck.push(-1);
    for(int i=0;i<N;++i)
    {
        while (sck.top()!=-1 && hi[sck.top()]>=hi[i])
        {
            peek = sck.top();
            sck.pop();
            s = max(s,hi[peek]*(i-sck.top()-1));
        }
        sck.push(i);
    }
    while(sck.top()!=-1)
    {
        peek = sck.top();
        sck.pop();
        s = max(s,hi[peek]*(N-sck.top()-1));
    }

    cout << s << endl;
    return 0;
}
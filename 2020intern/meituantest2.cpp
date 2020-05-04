#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q;

int main()
{
    int N,i=0,in;
    cin >> N;
    priority_queue<int,vector<int>,less<int>> que1; 
    priority_queue<int,vector<int>,less<int>> que2; 
    vector<vector<int>> dat(2,vector<int>{});
    while(i<N)
    {
        i++;
        cin >> in;
        que1.push(in);
    }
    i=0;
    while(i<N)
    {
        i++;
        cin >> in;
        que2.push(in);
    }
    int a =0,b=0;
    for(int j=0;j<3 && !que1.empty();j++)
    {
        a += que1.top();
        b += que2.top();
        que1.pop();
        que2.pop();
    }
    if(a>=b) cout << a << endl;
    else cout << b << endl;
    return 0;
}
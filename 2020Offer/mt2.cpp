#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a,b;
    string start = "";
    int res = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        if(start==""){
            start = a;
        }
        if(b == start)
        {
            res++;
            start="";
        }
    } 
    cout << res << endl;
    return 0;
}
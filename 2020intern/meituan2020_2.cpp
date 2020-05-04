#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
    int n,x,max = 0;
    int i=0,in,op;
    vector<int> dat;
    map<int,int> res;

    cin >> n >> x;

    while(i<n)
    {   
        i++;
        cin >> in;
        dat.push_back(in);
        res[in]++;
    }
    
    for(i=0;i<n;i++)
    {
        op = dat[i]&x ;
        if(op != dat[i])
            res[op]++;
        op = dat[i]|x ;
        if(op != dat[i])
            res[op]++;
    }
    
    for(auto re:res)
    {
        max = re.second > max ? re.second : max;
    }
    cout << max << endl;
    return 0;
}
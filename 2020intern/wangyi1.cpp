#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
    int n,m,s,x,y;
    cin >> n >> m >> s;
    vector<vector<int>> dat(m,vector<int>(2,0));
    vector<int> citys(n+1,0);
    int cnt = 0,res=0;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        dat[i][0] = x;
        dat[i][1] = y;
    }
    for(int i=0;i<m;i++)
    {
        x = dat[i][0];
        y = dat[i][1];
        if(x==0 && y==s)
        {
            res = i+1;
            cout << res <<endl;
            break;
        }    
        else if(x==0)
        {
            if(citys[y]==0)
            {
                citys[y]++;
                cnt++;
            }
        }
        else if(x==s && y!=s)
        {
            if(citys[y]==0)
            {
                citys[y]++;
                cnt++;
            }
        } 
        else if(x!=s && y==s)
        {
            if(citys[y]==0)
            {
                citys[y]++;
                cnt++;
            }
        }
        if(cnt >= n-1)  
        {
            cout << i+1 << endl;
            break;
        }  
    }
    if(res==0 && cnt< n-1)
    {
        cout << 0 << endl;
    }
    
    return 0;
}
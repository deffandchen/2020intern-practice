#include<bits/stdc++.h>

using namespace std;
int find(vector<int>& vec,int x)
{
    int r = x;
    while(vec[r]!=r)
    {
        r = vec[r];
    }
    int j = x;
    while(vec[j] !=j)
    {
        int tmp = vec[j];
        vec[j] = r;
        j = tmp;
    }
    return r;
}

void uni(vector<int>& vec,int x,int y)
{
    int xpar = find(vec,x);
    int ypar = find(vec,y);
    
    if(xpar <= ypar)
        vec[ypar] = xpar;
    else
    {
        vec[xpar] = ypar;
    }
}

int main()
{
    int n,m;
    cin >> n>>m;
    int a,b;
    //vector<vector<int>> dat(m,vector<int>(2,0));
    vector<int> bing(n+1,0);
    for(int i=1;i<=n;i++)
    {
        bing[i] = i;
    }
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        int ap = find(bing,a);
        int bp = find(bing,b);
        uni(bing,ap,bp);
    }
    vector<vector<int>> path;
    for(int i=1;i<=n;i++)
    {
        bing[i] = find(bing,i);   
    }
    for(int i=1;i<=n;i++)
    {
        if(bing[i]!=i) continue;
        vector<int> tmp;
        for(int j=i;j<=n;j++)
        {
            if(bing[j]==i)
            {
                tmp.push_back(j);
            }
        }
        if(!tmp.empty()) path.push_back(tmp);
    }
    cout << path.size() <<endl;
    for(int i=0;i<path.size();i++)
    {
        for(int j=0;j<path[i].size()-1;j++)
        {
            cout << path[i][j] << " ";
        }
        cout << path[i][path[i].size()-1] << endl;
    }

    return 0;
}
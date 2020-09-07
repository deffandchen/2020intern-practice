#include<iostream>
#include<vector>
 
using namespace std;
int res = 0,dis;
vector<int> data;
bool flag = false;
bool dfs(int idx,vector<int>& path)
{
    if(path.size()==2)
    {
        if((path[1] - path[0])>dis) return false;
        else return true;
    }
    else if(path.size()==3)
    {
        if((path[2] - path[0])>dis) return false;
        else
        {
            res++;
            res = res % 99997867;
            return true;
        }
    }
    for(int i=idx+1;i<data.size();)
    {
        path.push_back(data[i]);
        flag = dfs(i,path);
        path.pop_back();
        if(flag) i++;
        else break;
    }
}
int main()
{
    int n,tmp;
    cin >> n >> dis;
    vector<int> dat;
    while(n--)
    {
        cin >> tmp;
        dat.push_back(tmp);
    }
    data = dat;
    vector<int> path;
    for(int i=0;i<dat.size()-2;i++)
    {
        for(int j = i+1;j<dat.size()-1;j++)
        {
            if((dat[j] - dat[i]) < dis)
            {
                for(int k = j+1;k<dat.size();k++)
                {
                    if((dat[k] - dat[i]) < dis)
                       res++;
                    else
                        break;
                }
            }
            else{
                break;
            }
        }
    }
    cout << res << endl;
}
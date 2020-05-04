   #include<iostream>
   #include<vector>
#include<algorithm>

   using namespace std;
   
vector<vector<int>> res;
vector<int> vec;
int sum = 0;
int N =0;

void dfs(int n,int value,int sum)
{
    if(n==N) 
    {
        vec.push_back(sum);
        return ;
    }
    for(int i=1;i<=6;i++)
        dfs(n+1,i,sum+i);
}
vector<int> twoSum(int n) {
    N = n;
    dfs(0,1,0);
    return vec;
}
#include<map>
int main()
{
    int n = 2;
    vector<int> v = twoSum(n);
    sort(v.begin(),v.end());
    map<int,int> m;
    for(auto _v:v)
    {
        m[_v]++;
    }
    vector<double> ret;
    for(auto _m:m)
    {
        double d = (double)_m.second / v.size();
        ret.push_back(d);
    }
    return 0;
}
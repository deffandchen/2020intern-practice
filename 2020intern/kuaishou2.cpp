#include<bits/stdc++.h>

using namespace std;

vector<int> getpow(int R,int N)
{
    vector<int> ans;
    vector<int> nul;
    int n=0;
    if(R%N!=0 && (R-1)%N!=0) return ans;
    else
    {
        while(R)
        {
            if(R%N==0)
            {
                n++;
                R=R/N;
                continue;
            }
            else if((R-1)%N==0)
            {
                ans.push_back(n);
                n++;
                R = (R-1)/N;
            }
            else
                return nul;
        }
    }
    return ans;
}


int main()
{
    int R,N;
    cin >> R >> N;
    vector<int> res;
    res = getpow(R,N);
    
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

bool deng(int a,int b){
    string as = to_string(a);
    string bs = to_string(b);
    reverse(as.begin(),as.end());
    
    if(as == bs)
        return true;
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    int res = 0;
    vector<vector<int>> dat;

        int four = 0;
        vector<int> tmp;
        for(int i=1;i<=n;i++)
        {
            four = 4*i;
            if(four>n) continue;
            if(deng(i,four))
            {
                res++;
                tmp.push_back(i);
                tmp.push_back(four);
                dat.push_back(tmp);
                tmp.clear();
            }
        }

    cout << res << endl;
    for(int i=0;i<dat.size();i++)
    {
        cout << dat[i][0]<<' ' << dat[i][1] <<endl;
    }
    return 0;
}
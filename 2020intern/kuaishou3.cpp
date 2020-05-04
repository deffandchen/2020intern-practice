#include<bits/stdc++.h>

using namespace std;

vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<int> res;
    for(int i=1;i<=n;i++) res.push_back(i);
    for(int i=1;i<n;i++)
        for(int j=i;j>=0;j--)
        {

            swap(res[m],res[j]);
            for(int k=0;k<=i;k++)
            {
                if(k==0)
                int my = b[res[k]] *(i-k);
                else
                {
                    int my = a[res[k]] * (k-1) + b[res[k]] *(i-k);
                }
                my < 
            }
        }
}

int main()
{
    vector<int> a = {8,9,7};
    vector<int> b = {5,8,3};

    return 0;
}
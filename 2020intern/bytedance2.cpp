#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> mu(n,0);
    for(int i=0;i<n;i++)
    {
        cin >> mu[i];
    }
    int res=0,min_pos;
    for(int i= n-2;i>=0;i--)
    {
        int left = mu[i],right=mu[i+1];
        if(left>right)
        {
            int chu = left / right;
            int yu = left % right;
            if(yu>0)
            {
                res += chu;
                mu[i] = mu[i] / (chu+1);
            }
            else
            {
                res += chu-1;
                mu[i] = mu[i] / chu;
            }
        }
    }
    cout<< res << endl;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,l,n;
    int left,r;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> l >> n;
        vector<int> nums(l+1,0);
        for(int j=0;j<n;j++)
        {
            cin >> left >> r;
            for(int k = left; k <= r;k++)
            {
                nums[k]++;
            }
        }
        for(int idx = 1;idx<l;idx++)
        {
            cout << nums[idx] << " ";
        }
        cout << nums[l] << endl;
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> a(n,0);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        vector<int> left(n,0);//wangzuo
        vector<int> right(n,0);
        for(int i=1;i<n;i++)
        {
            int j = i-1;
            while(j>=0)
            {
               if(a[i]>=a[j])
               {
                   left[i] += left[j]+1;
                   j = j-left[j]-1;
               }
                else
                {
                    break;
                }
            }  
        }
        for(int i=n-2;i>=0;i--)
        {
            int j = i+1;
            while(j<n)
            {
               if(a[i]>=a[j])
               {
                   right[i]+= right[j]+1;
                   j = j+right[j]+1;
               }
                else
                {
                    break;
                }
            }  
        }
        for(int i=0;i<n-1;i++)
        {
            cout << left[i] + right[i] << ' ';
        }
        cout << left[n-1]+right[n-1] << endl;
    }
    return 0;
}
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
        vector<int> b(n,0);

        string ans="YES";
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin >> b[i]; 
        }
        int left=0,right=n-1;
        while(left<right)
        {
            if(a[left]==b[left])
                left++;
            else
            {
                break;
            }
            
        }
        while(right>=0)
        {
            if(a[right]==b[right])
                right--;
            else
            {
                break;
            }     
        }
        if(left<right)
        {
            int cha = b[left]-a[left];
            for(int i=left;i<=right;i++)
            {
                if(b[i]-a[i]!=cha)
                    ans = "NO";
            }
        }
        cout << ans << endl;
    }
    return 0;
}
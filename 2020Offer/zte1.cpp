#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,tmp;
    cin >> n;
    vector<int> vec1(n,0);
    vector<int> vec2(n,0);
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        vec1[i] = tmp;
    }
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        vec2[i] = tmp;
    }
    int res = 0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(vec1[i] > vec2[j])
               res++;
            else 
                break;
        }
    }
    cout << res << endl;
    return 0;
}
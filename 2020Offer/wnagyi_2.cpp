#include<bits/stdc++.h>

using namespace std;
static bool cmp(int a,int b)
{
    return a>=b;
}
int main()
{
    int t,n;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> n;
        int tmp,sumvalue = 0;
        vector<int> a(n,0);
        for(int j=0;j<n;j++)
        {
            cin >> tmp;
            a[j] = tmp;
            sumvalue += tmp;
        }
        int half = sumvalue / 2;
        vector<int> left;
        vector<int> right;
        int leftval=0,rightval=0;
        for(auto val:a){
            if(val< (half-leftval))
            {
                left.push_back(val);
                leftval += val;
            }
            else if(val < (half-rightval))
            {
                right.push_back(val);
                rightval += val;
            }
            else
            {
                if(leftval<rightval){
                    left.push_back(val);
                }
                else
                {
                    right.push_back(val);
                }
                
            }
        }
        sort(left.begin(),left.end(),cmp);
        sort(right.begin(),right.end(),cmp);
        if(leftval == rightval){
            int res = sumvalue - leftval - rightval;
            cout << res << endl;
        }
        else
        {
            while(leftval!=rightval){
                if(leftval>rightval)
                {
                    leftval = leftval - left[left.size()-1];
                    left.pop_back();
                }
                else if(leftval<rightval)
                {
                    rightval = rightval - right[right.size()-1];
                    right.pop_back();
                }
                if(left.empty() || right.empty())
                {
                    break;
                }
            }
            int res = sumvalue - leftval - rightval;
            cout << res << endl;
        }
        
    }
    return 0;
}

/*
void dfs(vector<int>& dat, int A, int B, int i)
{
 if (A == B) {
  maxSum = max(A, maxSum);
 }

 if (i >= dat.size() || A > sum / 2 || B > sum / 2) return;

 dfs(dat, A + dat[i], B, i + 1);
 dfs(dat, A, B, i + 1);
 dfs(dat, A, B + dat[i], i + 1);
}
*/
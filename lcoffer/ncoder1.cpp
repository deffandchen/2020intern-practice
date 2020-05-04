#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,l;
    cin >> n >> l; 
    int sum = 0,min=n;
    vector<int> ans;
    int i = n/2 + 1;
    int j = i;
    for(;i>0;i--)
    {
        sum += i;
        while(sum > n)
        {
            sum -= j;
            j--;
        }
        if(sum == n)
        {
            if(j-i+1 < min && j-i+1 >= l)
            {
                min = j-i+1;
                ans.clear();
                for(int k=i;k<=j;k++)
                    ans.push_back(k);
            }
        }
    }
    if(ans.size()>100 || ans.size()<2)
        cout << "No" << endl;
    else{
        for(int k=0;k<ans.size()-1;k++)
        {
            cout << ans[k] << ' ';
        }
        cout << ans[ans.size()-1]<< endl;
    }

    return 0;
}
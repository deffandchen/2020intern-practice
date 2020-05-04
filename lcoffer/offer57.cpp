#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,in,target,i=0;
    vector<int> dat;

    cin >> n;
    while(i<n)
    {
        cin >> in;
        dat.push_back(in);
        i++;
    }
    cin >> target;
    int left=0,right=0;
    for(i=0;i<n;i++)
    {
        if(target >= dat[i])
            right = i;
    }
    vector<int> res;
    while (left < right)
    {
        if(dat[left] + dat[right] > target)
            right--;
        else if(dat[left]+dat[right] < target)
            left++;
        else
        {
            res.push_back(dat[left]);
            res.push_back(dat[right]);
            left = right;
        }
    }
    if(!res.empty())
    {
        cout << res[0] << ' ' << res[1] << endl;
    }

    return 0;
}
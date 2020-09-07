#include<bits/stdc++.h>
using namespace std;
static bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first <= b.first)
        return true;
    else
    {
        return false;
    }
}


int main()
{
    vector<int> nums = {4,1,3,3,3};
    house(nums,5);
    return 0;
}


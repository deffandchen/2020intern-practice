#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool min_gather(string a,string b)
{
    return (a+b < b+a);
}

int main()
{
    vector<int> nums = {3,30,34,5,9};
    vector<string> res ;
    for(auto num:nums)
    {
        res.push_back(to_string(num));
    }
    sort(res.begin(),res.end(),min_gather);
    cout << res[0] << endl;
    return 0;
}
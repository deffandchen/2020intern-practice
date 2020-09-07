#include<bits/stdc++.h>
//排序
using namespace std;

void mysort(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
}

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> dat;
    int start = 0;
string tmp;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == ',' || i==str.size()-1)
        {
            tmp = str.substr(start,i);
            dat.push_back(stoi(tmp));
            tmp.clear();
            start = i+1;
        }
    }
    mysort(dat);
    string out;
    for(int i=0;i<n-1;i++)
    {
        out += to_string(dat[i]);
        out += ',';
    }
    out += to_string(dat[n-1]);
    cout << out << endl;
}
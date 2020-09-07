#include<bits/stdc++.h>

using namespace std;

int GetFragment(string str) {
    // write code here
    int nums = 0;
    int count = 0;
    if(str.empty()) return nums;
    int cnt = 1;
    for(int i=1;i<str.size();i++)
    {
        if(str[i] == str[i-1])
        {
            cnt++;
        }
        else
        {
            nums += cnt;
            count++;
            cnt = 1;
        }
    }
    nums += cnt;
    count++;
    return nums / count;
}
int main()
{

    return 0;
}
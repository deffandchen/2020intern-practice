#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N = 12;
    int ans = 0;
    int dat[N] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> left(N,0),right(N,0);
    //left[0] = dat[0];      //不需要考虑首尾的数据
    //right[0] = dat[N-1];
    for(int i=1;i<N;i++)
    {
        left[i] = max(left[i-1],dat[i-1]);
    }
    for(int i=N-2;i>=0;i--)
    {
        right[i] = max(right[i+1],dat[i+1]);
    }
    for(int i=1;i<N-1;i++)
    {
        int tmp = min(left[i],right[i]);
        ans += tmp > dat[i] ? tmp-dat[i]:0;
    }
    cout << ans << endl;
    return 0;
}

//遇到更大的 就从更大的开始
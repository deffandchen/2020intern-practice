#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> dat(N,0);//这里定义了N个0，此时dat里已经有N个0了
    int i=0,in;
    while(i<N)
    {
        cin >> in;
        dat[i] = in;//如果这里push 那就是从上面的N个0后开始，所以这里要直接用下标
        i++;
    }
    vector<int> dp(N,1);

    int j=0,max=0;
    for(i=1;i<N;i++)
    {
        j=i-1;
        while(j>=0)
        {
            if(dat[i] > dat[j])
                dp[i] = dp[i]>dp[j]+1?dp[i]:dp[j]+1;
            j--;
        }
        max = dp[i]>max?dp[i]:max;
    }
    cout << max <<endl;
    return 0;
}
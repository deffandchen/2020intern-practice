/*
题目：有一个2*n的网络，有一个人位于（1，1）的位置，即左上角，
他希望走到右下角即2n的位置，在每一次它可以进行三种操作中的一种：
1. 向右一格，即从(x,y)到(x,y+1)
2. 向上右方走一格，即如果他在(2,y)的位置可以走到(1,y+1)
3. 向下右方走一格，即如果他在(1,y)的位置可以走到(2,y+1)
有一部分格子有障碍物，不能走到障碍物上，问有多少种路线可以走到(2,n)
输入：第一行正整数n表示网格长度
接下来两行,每行n个字符，.表示可以停留，X表示不能停留：
....x...xx...
....x...xx...
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N,n=0;

    cin >> N;
    string in;
    vector<string> dat;
    while(n<2)
    {
        cin >> in;
        dat.push_back(in);
        n++;
    }

    vector<vector<int>> dp(2,vector<int>(N,0));
    dp[0][0] = 1;
    dp[1][0] = 0;
    for(int j=1;j<N;j++)  //j表示列
    {
        for(int i=0;i<2;i++)
        {   
            if(dat[i][j]=='.')
            {
                if(i==0)
                    dp[i][j] = dp[i][j-1] + dp[i+1][j-1];
                else
                {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }    
            }
        }
    }
    cout << dp[1][N-1] << endl;
    return 0;
}
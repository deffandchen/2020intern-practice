/*******************
题目：允许对二进制数进行两种操作：00->10,10->01，求可能的最大数(两种操作可以进行任意次)
输入格式：先一行输出样例数，然后每两行输入二进制长度与二进制数本体，1<=长度<=10000
例如：
2
4
0001
10
1010111000
输出格式：每行输出每个样例的答案
例如：
1101
1111101111
******************/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string dat;
    cin >> dat;
    int last = dat.size();
    for(int i=0;i<dat.size();i++)
    {
        if(dat[i]=='0')
        {
            last = i;
            break;
        }
    }
    for(int i=last+1;i<dat.size();i++)
    {
        if(dat[i]=='0')
        {
            if(i-last == 1)
            {
                dat[last] = '1';
                last = i;
            }   
            else
            {
                dat[i] = '1';
                dat[last+1] = '0';
                dat[last] = '1';
                last = last+1;
            }
        }
    }
    cout << dat << endl;
    return 0;
}
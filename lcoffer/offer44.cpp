#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int findNthDigit(int n) {
    vector<int> vec;
    long sum=0;
    int tmp,ans,i;
    if(n<10) return n;
    for(i=1;sum<n;i++)
    {
        tmp = pow(10,i) - pow(10,i-1);
        sum += tmp*i;
        if(sum > n) 
        {
            sum -= tmp*i;
            break;
        }
        vec.push_back(sum);
    }

    int chu = (n - sum)/i;
    int yu = (n-sum)%i;
    if(yu==0)
    {
        ans = ((int)pow(10,i-1) + chu - 1)%10;
    }
    else
    {
        int thnum = (int)pow(10,i-1) + chu;
        int juli = i - yu;
        while(juli--)
        {
            thnum /= 10;
        }
        ans = thnum % 10; 
    }
    return ans;
}

int main()
{
    findNthDigit(10);
}
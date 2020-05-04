#include<iostream>
#include<map>

using namespace std;

int main()
{
    string dat;
    cin >> dat;
    map<char,int> res;
    int len = dat.size();
    int start=0,max=0;
    for(int i=0;i<len;i++)
    {
        if(res.find(dat[i]) != res.end())
        {
            if(res[dat[i]] >= start)
                start = res[dat[i]] + 1;
            else
            {
                max = max>(i-start+1)?max:(i-start+1);
            }
        }
        else
        {
            max = max>(i-start+1)?max:(i-start+1);
        }
        res[dat[i]] = i;
    }
    cout << max <<endl;
    return 0;
}

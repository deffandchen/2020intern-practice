#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = to_string(n);
    int k=s.size()-1;
    for(int i=s.size()-2;i>=0;i--)
    {
        if(s[i] > s[i+1])
        {
            s[i] = s[i]-1;
            while (k>i)
            {
                s[k] = '9';
                k--;
            }
        }
    }
    int ans = stoi(s);
    cout << s << ' ' << ans <<  endl;
    return 0;
}
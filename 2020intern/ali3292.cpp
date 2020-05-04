/*
输入：一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
输出：对应每组数据,按字典序输出所有排列。

样例输入：
BCA
样例输出：
ABC
ACB
BAC
BCA
CAB
CBA

运行输入： AABBC
*/
#include<iostream>
#include<string>
#include<set>

using namespace std;

set<string> ans;

void dfs(string& s,int pos)
{
    if(pos == s.size())
    {
        ans.insert(s);
        return ;
    }
    else
    {
        for(int i=pos;i<s.size();i++)
        {
            swap(s[i],s[pos]);
            dfs(s,pos+1);
            swap(s[i],s[pos]);
        }
    }
}

int main()
{
    string s = "abc";
    dfs(s,0);
    for(auto a:ans)
    {
        cout << a << ' ';
    }
    cout << endl;

    return 0;
}
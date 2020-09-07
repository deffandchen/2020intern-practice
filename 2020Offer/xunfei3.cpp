#include<bits/stdc++.h>
//字符串去重
using namespace std;
char* delRe(char* str,char del)
{
    char* left = str;
    char* right = str;

    for(;*right!=0;++left,++right)
    {
        if(*right == del)
        {
            if(*(right+1) == del)
            {
                *left++ = *right;
                while(*right == del)
                {
                    ++right;
                }
                *left = *right;
                continue;
            }
        }
        *left = *right;
    }
    *left = 0;
    return str;
}
int main()
{
    string str;
    cin >> str;
    int pre,end;
    
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!='_')
        {
            pre = i;
            break;
        }
    }
    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]!='_')
        {
            end = i;
            break;
        }
    }
    
    str = str.substr(pre,end-pre+1);
    char* s = const_cast<char*> (str.c_str());
    str = string(delRe(s,'_'));
    cout << str << endl;
    return 0;
}
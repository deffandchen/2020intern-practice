/*
输入一个英文句子，翻转句子中单词的顺序，要求单词内字符的顺序不变，句子中单词以空格隔开，
为简单起见，标点符号和普通字母一样处理。
例如：输入“student. a am I”  输出 “I am a student.”。

思路：直接倒过来，不使用额外的空间，那就是原地交换。
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int start = s.size()-1;
    string sub;

    for(int i=s.size() - 1;i>=0;i--)
    {
        if(s[start] == ' ' && s[start-1]==' ')
        {
            start--;
        }
        if(s[i] == ' ' && i<start)
        {
            if(!sub.empty())
              sub += ' ';  
            sub += s.substr(i+1,start-i-1);
            start = i;
        }
        if(i==0 && s[i]!=' ')
        {
            if(!sub.empty())
              sub += ' ';  
            sub += s.substr(i,start);
        }
    }
    cout << sub << endl;
}
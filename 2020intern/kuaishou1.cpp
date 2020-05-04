#include<bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;

    stack<char> kuohao;
    int left =0,right=0,dui=0;
    for(int i=0;i<input.size();i++)
    {
        if(input[i] == '(')
        {
            kuohao.push(input[i]);
            left++;
        }
        else if(input[i]==')')
        {
            if(!kuohao.empty())
            {
                if(kuohao.top()=='(')
                {
                    kuohao.pop();
                    left--;
                    dui++;
                }
                else
                {
                    kuohao.push(input[i]);
                    right++;
                }
            }
            else
            {
                kuohao.push(input[i]);
                right++;
            }
            
        }
    }
    cout << dui << ' ' << left <<' '<<right<<endl;
    return 0;
}
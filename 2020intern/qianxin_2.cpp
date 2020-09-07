#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a = to_string(1);
    cout << a << endl;
    vector<int> vec;
    int tmp,s1 = 0,s2 = 0,s3 = 0;
    for(int i=0;i<9;i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
        if(i<=3) s1+=tmp;
        else if(i<=6) s2+=tmp;
        else s3+=tmp;
    }
    s2 += vec[3];
    s3 += vec[6]+vec[0];
    if(s1==s2 && s1==s3)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
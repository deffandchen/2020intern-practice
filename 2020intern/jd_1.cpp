#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m; //n个股 每天跑m个
    cin >> n >> m;
    //vector<int> value;
    priority_queue<int> que;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        que.push(tmp);
    }
    int wen;
    cin >> wen;
    vector<int> pao;
    for(int i=0;i<wen;i++)
    {
        int tmp;
        cin >> tmp;
        pao.push_back(tmp);
    }
    //sort(value.begin(),value.end());
    for(int i=0;i<pao.size();i++)
    {
        priority_queue<int> tmp;
        tmp = que;
        int zong_pao = pao[i];
        int del = n-zong_pao;
        while(del--)
        {
            tmp.pop();
        }
        int res = 0;
        int dat = 1;
        int j = zong_pao - 1;
        for(int i = zong_pao-1;i>=0;i--)
        {
            int guzhi = tmp.top();
            tmp.pop();
            res += dat*guzhi;
            if((j-i+1)==m)
            {
                dat++;
                j = i-1;
            }
        }

        cout<< res << endl;
    }

    return 0;
}
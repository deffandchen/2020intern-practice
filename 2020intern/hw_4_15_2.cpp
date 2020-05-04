#include<bits/stdc++.h>

using namespace std;

int main()
{
    string key,s;
    cin >> key >> s;
    int start = 0;
    string pkey;
    vector<string> res;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='[')
        {
            pkey = s.substr(start,i-start);
            if(pkey==key)
            {
                start = i+1;
            }
        }
        else if(s[i]==']')
        {
            if(s[start-1]=='[')
            {
                res.push_back(s.substr(start,i-start));
            }
        }
        else if(s[i]==',' && s[i-1]==']')
        {
            start = i+1;
        }
    }
    
    vector<vector<string>> ans; 
    for(int i=0;i<res.size();i++)
    {
        vector<string> tmp;
        string msg = res[i];
        int first = 0;
        for(int j=0;j<msg.size();j++)
        {
            if(msg[j]==',')
            {
                tmp.push_back(msg.substr(first,j-first));
                first = j+1;
            }
            else if(j==msg.size()-1)
            {
                tmp.push_back(msg.substr(first,j-first+1));
            }
        }
        if(!tmp.empty() && tmp.size()==3)
        {
            string addr,mask,val;
            string a,b,c;
            addr = tmp[0];
            mask = tmp[1];
            val = tmp[2];
            if(addr.size() > 7 && addr.substr(0,6)=="addr=0" && (addr[6]=='x'||addr[6]=='X'))
            {
                a = addr.substr(5,addr.size()-5);
            }
            if(mask.size() > 7 && mask.substr(0,6)=="mask=0" && (mask[6]=='x'||mask[6]=='X'))
            {
                b = mask.substr(5,mask.size()-5);
            }
            if(val.size() > 6 && val.substr(0,5)=="val=0" && (val[5]=='x'||val[5]=='X'))
            {
                c = val.substr(4,val.size()-4);
            }
            if(!a.empty() && !b.empty() && !c.empty())
            {
                int pos = ans.size();
                ans.push_back(vector<string>{a,b,c});
            }
        }
        
    }
    if(ans.empty())
    {
        cout << "FAIL" << endl;
    }
    else
    {
        for(int k=0;k<ans.size();k++)
        {
            for(int l=0;l<ans[k].size()-1;l++)
            {
                cout << ans[k][l] << ' ';
            }
            cout << ans[k][ans[k].size()-1] << endl;
        }     
    }
    
    return 0;
}
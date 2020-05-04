#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;

int N;
string p1,p2;
    
int main()
{
    map<string,int> model;
    vector<set<string>> vec;
    int order = 0;
    
    cin >> N;
    while(N--)
    {
        cin >> p1 >> p2;
        if(model.find(p2)==model.end())
        {
            model[p2] = order;
            vec.push_back(set<string>{p1}); 
            order++;
        }
        else
            vec[model[p2]].insert(p1);
    }
    for(auto i:model)
    {
        cout << i.first << ' ';
        for(auto s:vec[i.second])
            cout << s << ' ';
        cout << endl;
    }

    return 0;
}
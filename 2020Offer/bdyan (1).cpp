
#include<bits/stdc++.h>

using namespace std;


int main(){

    int  T = 0;
    cin >> T;
    // T 
    for(int i = 0; i < T; ++i){
        int n = 0; int m = 0;
        cin >> n >> m;

        vector<pair<int,int>> costs;
        vector<pair<int,int>> values;
        int tmp ;
        for(int i = 0; i < n; ++i){
            cin >> tmp;
            costs.push_back({tmp,i});
        }
        for(int i = 0; i < m; ++i){
            cin >> tmp;
            values.push_back({tmp,i});
        }

        sort(costs.begin(),costs.end(),[](const pair<int,int> &left,const pair<int,int> &right){ return left.first < right.first;});
        sort(values.begin(),values.end(),[](const pair<int,int> &left,const pair<int,int> &right){ return left.first < right.first;});

        vector<int> ans(n,-1);

        int idx = 0;
        for(int i = 0; i < n; ++i){
            while(idx < m && values[idx].first < costs[i].first) ++idx;
            if(idx == m) break;
            ans[costs[i].second] = values[idx].second + 1 ;
            ++idx;
        }

        for(int i = 0; i < n; ++i){
            cout << ans[i] <<' ';
        } 
        cout << endl;
    }
}







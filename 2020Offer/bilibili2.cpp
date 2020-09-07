#include<bits/stdc++.h>

using namespace std;


vector<int> SpiralMatrix(vector<vector<int> >& matrix) {
    // write code here
    vector<int> res;
    if(matrix.size()==0) return res;
    vector<pair<int,int>> direct = {{0,1},{1,0},{0,-1},{-1,0}};
    int i=0,j=-1;
    int m=matrix.size()-1,n=matrix[0].size();
    int dir = 0,time;
    while (m>=0 && n>= 0)
    {
        time = dir%2?m--:n--;
        for(int k=0;k<time;++k)
        {
            i += direct[dir].first;
            j += direct[dir].second;
            res.push_back(matrix[i][j]);
        }
        dir = (dir+1) % 4;
    }
    return res;
}

int main()
{
    vector<vector<int>> nums = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9,10,11,12}};
    SpiralMatrix(nums);
    return 0;
}
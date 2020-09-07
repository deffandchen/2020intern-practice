#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n,vector<int>(n,0));
    int mid = n / 2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<mid && j>=mid && i<(n-j))
            {
                vec[i][j] = 1;
            }
            else if(i<mid && j<mid && i<j)
            {
                vec[i][j] = 2;
            }
            else if(i<mid && j< mid && i>j)
            {
                vec[i][j] = 3;
            }
            else if(i>=mid && j<mid && i<(n-j))
            {
                vec[i][j] = 4;
            }
           else if(i>=mid && j<mid && i>(n-j-1))
            {
                vec[i][j] = 5;
            }
            else if(i>=mid && j>=mid && i>j)
            {
                vec[i][j] = 6;
            }
            else if(i>=mid && j>=mid && i<j)
            {
                vec[i][j] = 7;
            }
            else if(i<mid && j>=mid && i>=(n-j))
            {
                vec[i][j] = 8;
            }
            if(n%2 &&(i==mid || j==mid|| i==j || i==(n-j-1)))
            {
                vec[i][j] = 0;
            }
            if(n%2==0 && (i+j) == n-1)
            {
                vec[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            cout << vec[i][j] << ' ';
        }
        cout << vec[i][n-1]<<endl;
    }
    return 0;
}
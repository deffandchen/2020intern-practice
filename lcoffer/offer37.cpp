#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> nums;
bool flag = 0;
bool rowJudge(vector<vector<char>>& board,int xpos,char k)
{
    for(int i=0;i<4;i++)
    {
        if(k == board[xpos][i])
            return false;
    }
    return true;
}
bool colJudge(vector<vector<char>>& board,int ypos,char k)
{
    for(int i=0;i<4;i++)
    {
        if(k == board[i][ypos])
            return false;
    }
    return true;
}
bool kuangJudge(vector<vector<char>>& board,int xpos,int ypos,char k)
{
    int x_chu = xpos/2;
    int x_s = x_chu*2;
    int y_chu = ypos/2;
    int y_s = y_chu*2;

    for(int i=x_s;i<x_s+2;i++)
        for(int j=y_s;j<y_s+2;j++)
    {
        if(k == board[i][j])
            return false;
    }
    return true;
}

void dfs(int xpos,int ypos,char k)
{
    if(nums[xpos][ypos]!='.')
    {
        if(ypos<2) dfs(xpos,ypos+1,'1');
        else if(xpos<2) dfs(xpos+1,0,'1');
        else return;
    }
    else
    {
        for(char k='1';k<='9';k++)
        {
            if(rowJudge(nums,xpos,k) && colJudge(nums,ypos,k) && kuangJudge(nums,xpos,ypos,k))
            {
                nums[xpos][ypos] = k;
                if(ypos<4) dfs(xpos,ypos+1,'1');
                else if(xpos<4) dfs(xpos+1,0,'1');
                else 
                {
                    flag = 1;
                    return;
                }
            } 
        } 
        if(flag!=1)
            nums[xpos][ypos] = '.';
    }
}
void solveSudoku(vector<vector<char>>& board) {
    nums = board;
    dfs(0,0,'1');
    board = nums;
}

int main()
{
    vector<vector<char>> dat = {{'1','2','.','.'},{'3','.','4','.'},{'6','.','.','9'},{'5','.','.','.'}};
    solveSudoku(dat);
    return 0;
}
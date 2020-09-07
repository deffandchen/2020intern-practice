#include<bits/stdc++.h>

using namespace std; 
vector<int> vec;

struct node{
    int val;
    node* left;
    node* right;
    node(int x):val(x),left(NULL),right(NULL) {};//初始化列表效率更高
};

void dfs(node* root)
{
    if(root==NULL) return;
    if(root->left!=NULL) dfs(root->left);
    vec.push_back(root->val);
    if(root->right!=NULL) dfs(root->right);
}

int main()
{
    node* tmp = new node(1);
    tmp->left = new node(2);
    tmp->right = new node(3);
    dfs(tmp);
    for(int i=0;i<vec.size();i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}
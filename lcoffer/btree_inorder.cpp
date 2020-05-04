#include<iostream>
#include<vector>

using namespace std;

struct BTree{
    int val;
    BTree* left;
    BTree* right;
    BTree(int x) : val(x),left(NULL),right(NULL) {}
};

vector<int> res;
void dfs(BTree* root){
    if(root!=NULL)
    {
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }  
    else
    {
        return ;
    }
}

void order(BTree* root)
{
    if(root == NULL)
        return ;
    else
    {
        order(root->left);
        res.push_back(root->val);
        order(root->right);
    }
}

int main()
{
    BTree* bt = new BTree(1);
    bt->left = new BTree(2);
    bt->right = new BTree(3);
    bt->left->left = new BTree(4);
    bt->right->right = new BTree(5);
    dfs(bt);
    for(auto r:res)
    {
        cout << r << ' ';
    }
    cout << endl;
    order(bt);
    for(auto r:res)
    {
        cout << r << ' ';
    }
    return 0;
}
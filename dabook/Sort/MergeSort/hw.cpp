#include<bits/stdc++.h>

struct node{
    int val;
    node* left;
    node* right;
    node(int x):val(x),left(NULL),right(NULL){};
};

int depth(node* root){
    if(root==NULL) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    return left>right?left+1:right+1; 
}

int main()
{   
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->right = new node(3);
    std::cout << depth(root) << std::endl;
    return 0;
}
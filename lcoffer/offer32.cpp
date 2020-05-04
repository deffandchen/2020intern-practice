#include<iostream>
#include<vector>
#include<deque>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    deque<TreeNode*> deq;
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    else deq.push_front(root);
    vector<int> tmp;
    int level = 1;
    TreeNode* end = root;
    while(!deq.empty())
    {
        if(level%2==1)
        {
            while(1)
            {
                TreeNode* node = deq.front();
                tmp.push_back(node->val);
                deq.pop_front();
                if(node->left!=NULL) deq.push_back(node->left);
                if(node->right!=NULL) deq.push_back(node->right);
                if(node == end)
                {
                    level++;
                    end = deq.front();
                    break;
                }
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        else
        {
            while(1)
            {
                TreeNode* node = deq.back();
                tmp.push_back(node->val);
                deq.pop_back();
                if(node->right!=NULL) deq.push_front(node->right);
                if(node->left!=NULL) deq.push_front(node->left);
                if(node == end)
                {
                    level++;
                    end = deq.back();
                    break;
                }
            }
            ans.push_back(tmp);
            tmp.clear();
        }
    }
    return ans;
}

int main()
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);
    levelOrder(node);
    return 0;
}
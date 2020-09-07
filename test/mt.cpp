#include<bits/stdc++.h>
#include<vector>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};
bool quickSlow(ListNode* root){
    if(!root) return false;
    ListNode* pre = root;
    ListNode* cur = root;
    while(pre->next)
    {
        pre = pre->next->next;
        cur = cur->next;
        if(pre == cur)
        {
            return true;
        }
    }
    return false;
}
int main() {
    vector<int> nums = {1,2};
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for(int i=1;i<nums.size();i++)
    {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    //cur->next = head;
    if(quickSlow(head))
       cout << "Hello World!" << endl;
    else
        cout << "false" << endl;
    return 0;
}
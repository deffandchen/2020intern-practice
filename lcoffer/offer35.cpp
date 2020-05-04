#include<iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;

    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    return head;
}

int main()
{
    Node* list = new Node(1);
    list->next = new Node(2);
    Node* res = copyRandomList(list);
    cout << res->next->val << endl;
    return 0;
    
}
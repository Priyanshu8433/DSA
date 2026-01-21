/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* itr=head;
        Node* newHead=new Node(-1);
        Node* last=newHead;

        while(itr){
            last->next=new Node(itr->val);
            mp[itr]=last->next;
            last=last->next;
            itr=itr->next;
        }

        itr=head;
        Node* curr=newHead->next;
        while(itr){
            curr->random=mp[itr->random];
            curr=curr->next;
            itr=itr->next;
        }

        return newHead->next;
    }
};
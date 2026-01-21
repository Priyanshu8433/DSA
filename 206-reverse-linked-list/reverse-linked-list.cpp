/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode* node, ListNode* prev){
        if(!node) return prev;
        ListNode* next=node->next;
        node->next=prev;
        return solve(next,node);
    }

    ListNode* reverseList(ListNode* head) {
        return solve(head,nullptr);
    }
};
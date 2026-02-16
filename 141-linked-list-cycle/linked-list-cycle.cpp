/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *slow=head,*fast=head;

        do{
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
            if(slow==fast && slow) return true;
        }while(fast && slow!=fast);

        return false;
    }
};
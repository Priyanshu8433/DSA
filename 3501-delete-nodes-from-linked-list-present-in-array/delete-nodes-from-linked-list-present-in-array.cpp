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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(int x: nums) st.insert(x);
        ListNode *p=NULL;
        ListNode *q=head;
        ListNode *r=head->next;

        while(q){
            if(st.count(q->val)){
                //delete the node
                if(!p) head=r;
                else p->next=r;
            }
            else p=q;
            q=r;
            if(r) r=r->next;
        }
        return head;
    }
};
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        ListNode* itr=headA;
        while(itr){
            st.insert(itr);
            itr=itr->next;
        }

        itr=headB;
        while(itr){
            if(st.count(itr)) return itr;
            itr=itr->next;
        }
        return nullptr;
    }
};
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp =[](ListNode* a, ListNode* b){
            return a->val>b->val;
        };

        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);

        for(auto list: lists){
            if(list) pq.push(list);
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* last=dummy;

        while(!pq.empty()){
            ListNode *list=pq.top();
            pq.pop();
            last->next=list;
            last=last->next;
            list=list->next;
            last->next=NULL;
            if(list) pq.push(list);
        }

        return dummy->next;
    }
};
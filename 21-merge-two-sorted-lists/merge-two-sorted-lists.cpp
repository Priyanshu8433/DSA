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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=NULL,*itr1=list1,*itr2=list2,*last=nullptr;

        if(!list1) return list2;
        if(!list2) return list1;
        
        while(itr1 && itr2){
           if(itr1->val<itr2->val){
                if(!head){
                    head=itr1;
                    last=head;
                }
                else{
                    last->next=itr1;
                    last=last->next;
                }
                itr1=itr1->next;
           }
           else{
                if(!head){
                    head=itr2;
                    last=head;
                }
                else{
                    last->next=itr2;
                    last=last->next;
                }
                itr2=itr2->next;
            }
        }
        if(itr1) last->next=itr1;
        else last->next=itr2;
        return head;
    }
};
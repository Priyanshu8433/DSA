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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head,*fast=slow->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy=new ListNode(-1);
        ListNode *itr1=head1, *itr2=head2, *temp=dummy;
        while(itr1 && itr2){
            if(itr1->val<itr2->val){
                temp->next=itr1;
                temp=itr1;
                itr1=itr1->next;
            }
            else{
                temp->next=itr2;
                temp=itr2;
                itr2=itr2->next;
            }
        }

        if(itr1) temp->next=itr1;
        else temp->next=itr2;

        return dummy->next;
    }

    ListNode* mergesort(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* middle=findMiddle(head);
        ListNode* next=middle->next;
        middle->next=NULL;
        head=mergesort(head);
        next=mergesort(next);
        return merge(head,next);
    }

    ListNode* sortList(ListNode* head) {
        // ListNode* last=head;
        // while(last->next) last=lasy->next;
        return mergesort(head);
    }
};
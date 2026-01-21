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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *oPrev=NULL,*start=head,*last=head;

        while(last){
            int temp=k;
            while(last && temp>0){
                last=last->next;
                temp--;
            }
            if(temp!=0){
                cout<<temp;
                return head;
            }

            // reverse now
            ListNode *curr=start,*prev=last;
            while(curr!=last){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            if(!oPrev) head=prev;
            else oPrev->next=prev;
            oPrev=start;
            start=last;
        }
        return head;
    }
};
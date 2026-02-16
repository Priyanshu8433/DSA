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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        int idx=1;
        ListNode* even=NULL, *itr=NULL;
        ListNode *prev=NULL,*curr=head,*ahead=head->next;

        while(curr){
            if(idx%2==0){
                prev->next=ahead;
                curr->next=NULL;

                if(!itr){
                    even=curr;
                    itr=even;
                }
                else{
                    itr->next=curr;
                    itr=itr->next;
                }
                curr=ahead;
                if(ahead)
                    ahead=ahead->next;
            }
            else{
                prev=curr;
                curr=ahead;
                if(ahead)
                    ahead=ahead->next;
            }

            idx++;
        }

        prev->next=even;

        return head;
    }
};
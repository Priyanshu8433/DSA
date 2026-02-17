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
    ListNode* reverse(ListNode* curr, ListNode *prev){
        if(!curr) return prev;

        ListNode* nextNode=curr->next;
        curr->next=prev;
        return reverse(nextNode,curr);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *subHead=head,*subTail=head;
        ListNode *prevTail=NULL;

        while(subTail){
            int t=k-1;

            while(subTail && t>0){
                subTail=subTail->next;
                t--;
            }

            if(t>0 || !subTail) break;

            ListNode *nextHead=subTail->next;
            subTail->next=NULL;

            ListNode *revHead=reverse(subHead,NULL);

            if(prevTail==NULL){
                head=revHead;
            }
            else{
                prevTail->next=revHead;
            }
            subHead->next=nextHead;
            prevTail=subHead;
            subHead=nextHead;
            subTail=nextHead;
        }

        return head;
    }
};
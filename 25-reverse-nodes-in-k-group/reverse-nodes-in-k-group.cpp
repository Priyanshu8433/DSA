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
    ListNode* reverse(ListNode* curr, ListNode* prev){
        if(!curr) return prev;

        ListNode* nextNode=curr->next;
        curr->next=prev;

        return reverse(nextNode,curr);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *subHead=head;
        ListNode *prevTail=NULL;

        while(subHead){
            ListNode *subTail=subHead;
            int tempK=k-1;

            while(subTail && tempK){
                subTail=subTail->next;
                tempK--;
            }

            if(!subTail) break;

            ListNode *nextHead=subTail->next;
            subTail->next=NULL;

            ListNode* revHead=reverse(subHead,NULL);

            if(prevTail==NULL){
                head=revHead;
            }
            else{
                prevTail->next=revHead;
            }
            subHead->next=nextHead;

            prevTail=subHead;
            subHead=nextHead;
        }

        return head;
    }
};
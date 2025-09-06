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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        return 1;
        ListNode *temp=head;
        int count =0;
        while(temp){
            count++;
            temp=temp->next;
        }
        count/=2;
        ListNode *cur=head, *prev=NULL;
        while(count--){
            prev=cur;
            cur=cur->next;
        }
        prev->next=NULL;


        prev=NULL;
        ListNode*fut=NULL;
        while(cur){
            fut=cur->next;
            cur->next=prev;
            prev=cur;
            cur=fut;
        }
        ListNode *h1=head, *h2=prev;
        while(h1){
            if(h1->val != h2->val)
            return 0;

            h1=h1->next;
            h2=h2->next;
        }
        return 1;
    }
};
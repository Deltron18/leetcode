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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        count-=n;
        if(count==0){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode *cur=head;
        ListNode *prev = NULL;
        while(count--){
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        delete cur;


return head;
    }
};
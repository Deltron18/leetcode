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
    ListNode* reverseList(ListNode* head) {


        // vector<int>ans;       //using extra array and reversing valus not nodes
        // ListNode *temp=head;
        // while(temp!=NULL){
        //     ans.push_back(temp->val);
        //     temp=temp->next;
        // }
        // int i=ans.size()-1;
        // temp=head;
        // while(temp){
        //     temp->val=ans[i];
        //     i--;
        //     temp=temp->next;
        // }
        // return head;



        // by actually  reversing the nodes
        ListNode *cur= head, *prev=NULL, *fut=NULL;

        while(cur){
            fut=cur->next;
            cur->next = prev;
            prev=cur;
            cur=fut;
        }
        head=prev;

        return head;



    }
};
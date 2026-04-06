/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head==NULL)
        {return head;}
        Node *cur=head;
        while(cur!=NULL){
            if(cur->child!=NULL){
                Node*fut=cur->next;
                cur->next=flatten(cur->child);
                cur->next->prev=cur;
                cur->child=NULL;
                while(cur->next!=NULL){
                    cur=cur->next;
                }
                if(fut!=NULL){
                        cur->next=fut;
                        fut->prev=cur;
                }
            }
            else
            cur=cur->next;
        }
        return head;
    }
};
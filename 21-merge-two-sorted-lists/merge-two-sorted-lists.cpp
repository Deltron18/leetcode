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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // dummy node to simplify logic
        // ListNode dummy(0);
        // ListNode* tail = &dummy;

        // while (list1 && list2) {
        //     if (list1->val < list2->val) {
        //         tail->next = list1;
        //         list1 = list1->next;
        //     } else {
        //         tail->next = list2;
        //         list2 = list2->next;
        //     }
        //     tail = tail->next;
        // }

        // // append the remaining nodes
        // if (list1) tail->next = list1;
        // else tail->next = list2;

        // return dummy.next;


        //using recursion
        if(l1==NULL || l2==NULL)
        return l1 == NULL ? l2 : l1;

        if(l1->val<=l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }

    }
};

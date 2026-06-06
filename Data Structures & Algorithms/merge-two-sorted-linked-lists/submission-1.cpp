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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return list1;

        if(list1 == nullptr) return list2;

        if(list2 == nullptr) return list1;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* merge = new ListNode();
        ListNode* head = merge;
        while(curr1 && curr2){

            if(curr1->val <=curr2->val){
                merge->next = curr1;
               
                curr1=curr1->next;
            } else {
                merge->next = curr2;
                curr2=curr2->next;
            }
             merge = merge->next;
        }

        if(curr1){
            merge->next = curr1;
                
        }

        if(curr2){
             merge->next = curr2;
             
        }

        return head->next;
    }
};

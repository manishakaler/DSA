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
        int size = 0;
        ListNode* curr = head;

        while(curr != NULL){
            size++;
            curr = curr->next;
        }
        
        int index = size - n;
        curr = head;
        if(index == 0){
            head = head->next;
        } else {
            for(int i = 0; i < size -1 ; i++){
                if(i+1 == index){
                    curr->next = curr->next->next;
                    break;
                }
                curr = curr->next;
            }
        }

        return head;
    }
};

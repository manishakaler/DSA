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
    ListNode* recursion(ListNode* node){
        if(node == nullptr || node->next == nullptr){
            return node;  //empty list or tail
        }

        ListNode* head = recursion(node->next);

        node->next->next = node;
        node->next = nullptr;

        return head;
        
    }

    ListNode* reverseList(ListNode* head) {
    //     if(head == nullptr) return nullptr;

    //     ListNode* prev = nullptr;
    //     ListNode* curr = head;
    //     ListNode* temp = head->next;

    //     while(curr!=nullptr){
    //         temp = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = temp;
    //     }
    //  //   curr->next = prev;

    //     return prev;
        return recursion(head);
    }
};

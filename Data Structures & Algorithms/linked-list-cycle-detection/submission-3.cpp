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
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;

        // //naive - use hashset
        // unordered_set<ListNode*>nodeSet;

        // while(head!=nullptr){
        //     if(nodeSet.count(head)){
        //         return true;
        //     }
        //     nodeSet.insert(head);
        //     head=head->next;
        // }

        // return false;
        // //naive end
        // //naive TC: O(n) worst case , SC: O(N)

    //slow fast start
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr){

            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }

        return false;
    //slow fast end
    //slow fast TC: O(N) worst case | SC: O(1)


    }


};

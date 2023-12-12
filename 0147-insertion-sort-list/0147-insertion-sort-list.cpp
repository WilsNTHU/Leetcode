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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return nullptr;
        else{
            head->next = insertionSortList(head->next);
            if(!head->next) return head;
            if(head->val <= head->next->val) return head; // already sorted
            else{
                ListNode *cur = head;
                ListNode *to_return = head->next;
                while(cur->next && (head->val > cur->next->val)){
                    cur = cur->next;
                }
                head->next = cur->next;
                cur->next = head;
                return to_return;
            }
        }
    }
    
};
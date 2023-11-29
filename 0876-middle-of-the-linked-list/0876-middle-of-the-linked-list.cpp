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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            len++;
        }
        
        ptr = head;
        for(int i=0; i<len/2; i++) ptr = ptr->next;
        return ptr;
    }
};
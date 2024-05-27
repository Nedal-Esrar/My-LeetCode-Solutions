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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* cur = head, *prv = dummy;

        while (cur != nullptr && cur->next != nullptr) {
            prv->next = cur->next;
            cur->next = prv->next->next;
            prv->next->next = cur;
            
            prv = cur;
            cur = cur->next;
        }
        
        return dummy->next;
    }
};
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* tmp = nullptr;

        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);

        int mx = 0;
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            mx = max(mx, cur->val);

            if (cur->val < mx) {
                prev->next = cur->next;
                ListNode* deleted = cur;
                cur = cur->next;
                deleted->next = nullptr;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return reverseList(head);
    }
};
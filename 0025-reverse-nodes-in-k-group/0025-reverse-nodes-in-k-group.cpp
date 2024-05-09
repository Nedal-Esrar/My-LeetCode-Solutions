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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*
            The idea is traversing the whole list, divide to k-lists, reverse the k-list, rejoin with the whole list.
            1. get the node that is the kth node to the current traversal node.
            2. disconnect it from the whole list.
            3. reverse the list.
            4. reconnect the list to the original list.
        */
        ListNode* trav = head;
        ListNode* previous = nullptr;
        
        while (trav != nullptr) {
            ListNode* kth_node = get_kth_node(trav, k);
            
            if (kth_node == nullptr) { // the remaining segment size is less than k
                if (previous != nullptr) {
                    previous->next = trav;
                }
                
                return head;
            }
            
            ListNode* next = kth_node->next;
            
            kth_node->next = nullptr;
            
            reverse(trav);
            
            if (previous == nullptr) {
                head = kth_node;
            } else {
                previous->next = kth_node;
            }
            
            previous = trav;
            trav = next;
        }
        
        return head;
    }
private:
    ListNode* get_kth_node(ListNode* node, int k) {
        --k;
        
        while (node != nullptr && k != 0) {
            node = node->next;
            
            --k;
        }
        
        return node;
    }
    
    ListNode* reverse(ListNode* node) {
        ListNode* reversed = node, *reversed_next = reversed->next;
        
        reversed->next = nullptr;
        
        while (reversed_next != nullptr) {
            ListNode* tmp = reversed_next->next;
            reversed_next->next = reversed;
            reversed = reversed_next;
            reversed_next = tmp;
        } 
        
        return reversed;
    }
};
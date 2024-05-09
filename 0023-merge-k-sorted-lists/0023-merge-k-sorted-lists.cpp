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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // for this problem, maintain multi pointer to keep track of progress in each list separately
        // but checking for the minimum in these current pointer is very costly in the classic way
        // so here is a solution
        // maintain a priority queue to extract the minimum value in an effecient way
        // the queue will maintain only n Nodes at an instance where n is the number of lists
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> q(
            [](ListNode* l1, ListNode* l2) { return l1->val > l2->val; }
        );
        
        for (ListNode* list : lists) {
            if (list == nullptr) {
                continue;
            }
            
            q.push(list);
        }
        
        ListNode* ret = new ListNode(); // dummy node for ease in solving the problem.
        ListNode* trav = ret;
        
        while (!q.empty()) {
            ListNode* min_node = q.top();
            q.pop();
            
            trav->next = min_node;
            
            if (min_node->next != nullptr) {
                q.push(min_node->next);
            }
            
            trav = trav->next;
        }
        
        return ret->next;
    }
};
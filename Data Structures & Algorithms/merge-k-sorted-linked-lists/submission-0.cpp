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

struct comp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
private:
    ListNode* addAtBack(ListNode* tail, ListNode* node) {
        tail->next = node;
        return node;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;

        for (auto node : lists)
            if (node) pq.push(node);
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            tail = addAtBack(tail, top);
            if (top->next) {
                pq.push(top->next);
            }
        }

        return dummy->next;

    }
};
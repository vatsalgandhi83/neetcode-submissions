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
private:
    ListNode* reverseK(ListNode* start, ListNode* end) {
        ListNode* curr = start;
        ListNode* prev = end;
        while(curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode* temp = head;
        ListNode* result = temp;

        for(int i = 0; i < k - 1; i++) {
            if(temp)
                temp = temp->next;
            else
                return result;
        }
        result = temp;
        temp = head;
        ListNode* prev = NULL;

        while(temp != NULL) {

            ListNode* temp2 = temp;

            for (int i = 0; i < k - 1; i++) {
                if (temp->next) {
                    temp = temp->next;
                } else {
                    return result;
                }
            }

            ListNode* tempNext = temp->next;
            temp = reverseK(temp2, temp->next);
            
            if (prev) {
                prev->next = temp;
            }
            prev = temp2;
            temp = tempNext; 
        }
        return result;
    }
};
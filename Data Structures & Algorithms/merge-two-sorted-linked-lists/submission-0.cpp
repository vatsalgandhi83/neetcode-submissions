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
    ListNode* addAtBack(ListNode* tail, int val) {
        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        return newNode;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode(0); // just to start the result LinkedList..
        ListNode* temp1 = list1, *temp2 = list2, *temp3 = result;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val < temp2->val) {
                temp3 = addAtBack(temp3, temp1->val);
                temp1 = temp1->next;
            } else {
                temp3 = addAtBack(temp3, temp2->val);
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL) {
            temp3 = addAtBack(temp3, temp1->val);
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            temp3 = addAtBack(temp3, temp2->val);
            temp2 = temp2->next;
        }

        return result->next;

    }
};
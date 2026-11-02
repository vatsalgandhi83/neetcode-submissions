class Solution {
private:
    ListNode* addAtBack(ListNode* tail, int val) {
        ListNode* temp = new ListNode(val);
        tail->next = temp;
        return temp;
    }

    int getVal(ListNode* node) {
        return node ? node->val : 0;
    }

    ListNode* getNext(ListNode* node) {
        return node ? node->next : nullptr;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (l1 || l2 || carry) {
            int sum = getVal(l1) + getVal(l2) + carry;
            carry = sum / 10;
            tail = addAtBack(tail, sum % 10);

            l1 = getNext(l1);
            l2 = getNext(l2);
        }

        return dummy->next;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* temp = head;

        unordered_map<Node*, Node*> oldNewMap;

        while(temp != NULL) {
            Node* t = new Node(temp->val);
            oldNewMap[temp] = t;
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL) {
            oldNewMap[temp]->next = oldNewMap[temp->next];
            oldNewMap[temp]->random = oldNewMap[temp->random];
            temp = temp->next;
        }

        return oldNewMap[head];





        // Node* temp = head;

        // unordered_map<int, Node*> valNodeMap;
        // unordered_map<int, int> randomValMap;

        // while (temp != NULL) {
        //     Node* t = new Node(temp->val);
        //     valNodeMap[temp->val] = t;
        //     randomValMap[temp->val] = temp->random ? temp->random->val : NULL;
        //     temp = temp->next;
        // }

        // Node* result = new Node(INT_MIN);
        // Node* resultTail = result;
        // temp = head;
        // while(temp != NULL) {
        //     resultTail->next = valNodeMap[temp->val];
        //     resultTail->next->random = randomValMap[resultTail->val] ? randomValMap[resultTail->val] : NULL;
        //     temp = temp->next;
        // }

        // return result->next;

    }
};
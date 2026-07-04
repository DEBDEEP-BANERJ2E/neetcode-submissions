class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr; Node* curr = head;
        while (curr != nullptr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* newHead = head->next; curr = head;
        while (curr != nullptr) {
            Node* clone = curr->next;
            curr->next = clone->next; 
            if (clone->next != nullptr)
                clone->next = clone->next->next;
            curr = curr->next;
        }
        return newHead;
    }
};

#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

            Node* findKthFromEnd(int k) {
    Node* slow = head;
    Node* fast = head;

    // Move 'fast' k nodes ahead
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) return nullptr; // k is greater than the length of the list
        fast = fast->next;
    }

    // Move both 'slow' and 'fast' until 'fast' reaches the end of the list
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // 'slow' now points to the k-th node from the end
    return slow;
}
       
};

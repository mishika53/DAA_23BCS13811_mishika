#include <iostream>
using namespace std;

class CircularLinkedList {
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    CircularLinkedList() : head(NULL) {}

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, NULL};
        if (head == NULL) {
            head = newNode;
            head->next = head; // circular
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL};
        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    // Delete from beginning
    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        if (head->next == head) { // only one node
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = NULL;
            return;
        }
        Node* last = head;
        while (last->next != head) last = last->next;
        head = head->next;
        last->next = head;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    }

    // Delete from end
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        if (head->next == head) { // only one node
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = NULL;
            return;
        }
        while (temp->next->next != head) temp = temp->next;
        Node* last = temp->next;
        temp->next = head;
        cout << "Deleted: " << last->data << endl;
        delete last;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtBeginning(5);
    cll.insertAtEnd(20);
    cll.display();

    cll.deleteAtBeginning();
    cll.display();

    cll.deleteAtEnd();
    cll.display();

    return 0;
}

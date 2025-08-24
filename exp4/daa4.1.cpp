#include <iostream>
using namespace std;

class DoublyLinkedList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, NULL, head};
        if (head != NULL) head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL, NULL};
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete from beginning
    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
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
        if (temp->next == NULL) { // only one node
            cout << "Deleted: " << temp->data << endl;
            delete temp;
            head = NULL;
            return;
        }
        while (temp->next != NULL) temp = temp->next;
        temp->prev->next = NULL;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.display();

    dll.deleteAtBeginning();
    dll.display();

    dll.deleteAtEnd();
    dll.display();

    return 0;
}

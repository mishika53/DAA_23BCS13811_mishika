#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    int top;
    int capacity;
    T *arr;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if stack is full
    bool isFull() {
        return (top == capacity - 1);
    }

    // Push operation
    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack." << endl;
        }
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Get the top element
    T peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty! No top element.");
        }
        return arr[top];
    }
};

// Driver code
int main() {
    Stack<int> s(5); // stack of integers with size 5

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;

    // Check empty and full
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val, Node* n = nullptr) {
        value = val;
        next = n;
    }
};

class ListStack {
private:
    Node* head;
    int count;

public:
    ListStack() {
        head = nullptr;
        count = 0;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    int top() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return head->value;
    }

    void push(int val) {
        head = new Node(val, head);
        count++;
    }

    int pop() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        int val = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return val;
    }
};

int main() {
    ListStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl;
    cout << "Size of stack: " << stack.size() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    return 0;
}
// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <stdexcept>
using namespace std;

class Queue {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    int size() { return count; }
    bool empty() { return count == 0; }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int peek() {
        if (empty()) {
            throw invalid_argument("QueueEmptyException");
        }
        return head->value;
    }

    void enqueue(int value) {
        Node* temp = new Node(value, nullptr);
        if (empty()) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        count++;
    }

    int dequeue() {
        if (empty()) {
            throw invalid_argument("QueueEmptyException");
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 100; i++) {
        q.enqueue(i);
    }
    for (int i = 1; i <= 50; i++) {
        q.dequeue();
    }
    q.print();
    return 0;
}
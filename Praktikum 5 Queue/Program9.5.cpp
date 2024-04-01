// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class QueueUsingStack {
private:
    stack<int> inbox, outbox;

public:
    void enqueue(int value) {
        inbox.push(value);
    }

    int dequeue() {
        if (outbox.empty()) {
            if (inbox.empty()) {
                throw invalid_argument("QueueEmptyException");
            }
            while (!inbox.empty()) {
                int value = inbox.top();
                inbox.pop();
                outbox.push(value);
            }
        }
        int frontValue = outbox.top();
        outbox.pop();
        return frontValue;
    }
};

int main() {
    QueueUsingStack queue;
    queue.enqueue(1);
    queue.enqueue(11);
    queue.enqueue(111);
    cout << queue.dequeue() << endl;  // Output: 1
    queue.enqueue(2);
    queue.enqueue(21);
    queue.enqueue(211);
    cout << queue.dequeue() << endl;  // Output: 11
    cout << queue.dequeue() << endl;  // Output: 111
    return 0;
}
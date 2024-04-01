// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> stk;

    // Step 1: Dequeue semua elemen dari queue ke dalam stack
    while (!q.empty()) {
        stk.push(q.front());
        q.pop();
    }

    // Step 2: Menampilkan semua elemen dari stack dan menambahkannya ke dalam queue
    while (!stk.empty()) {
        q.push(stk.top());
        stk.pop();
    }
}

int main() {
    queue<int> q;

    // Push element ke dalam queue
    for (int i = 1; i <= 5; ++i) {
        q.push(i);
    }

    cout << "Original queue: ";
    queue<int> temp = q; // Mengcopy queue untuk ditampilkan
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Mereverse queue nya
    reverseQueue(q);

    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
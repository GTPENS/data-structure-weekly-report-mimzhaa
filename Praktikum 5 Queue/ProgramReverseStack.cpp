// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseStack(stack<int>& stk) {
    queue<int> q;

    // Step 1: Menampilkan semua elemen stack dan menambahkannya ke dalam queue
    while (!stk.empty()) {
        q.push(stk.top());
        stk.pop();
    }

    // Step 2: Menghapus semua elemen dari queue di dalam stack
    while (!q.empty()) {
        stk.push(q.front());
        q.pop();
    }
}

int main() {
    stack<int> s;

    // Push element ke dalam stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original stack: ";
    stack<int> temp = s; // Mengcopy stack untuk ditampilkan
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Mereverse stack nya
    reverseStack(s);

    cout << "Reversed stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
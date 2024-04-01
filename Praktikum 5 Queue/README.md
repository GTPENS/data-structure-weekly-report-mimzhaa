
## Nama    : Marlon Immanuel Sarapang
## NRP     : 52236000010
## Kelas   : GT11-A

# Praktikum 5: Overview Queue

1. **Queue Menggunakan Linked List**

Program ini mempergunakan struktur data Queue dengan basis Linked List.

```cpp
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
```

2. **Enqueue pada Queue Linked List**

Program ini hanya berfokus pada pelaksanaan metode enqueue yang bertugas menambahkan elemen baru ke akhir dari antrian menggunakan struktur data linked list.
```cpp
void Queue::enqueue(int value) {
    Node* temp = new Node(value, nullptr);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    count++;
}
```

3. **Dequeue pada Queue Linked List**

Program ini hanya mengandung implementasi metode dequeue yang bertugas menghapus elemen dari awal Queue yang diimplementasikan menggunakan Linked List.
```cpp
int Queue::dequeue() {
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
```

4. **Implementasi Queue menggunakan 2 Stack**

Program ini memanfaatkan dua tumpukan (Stack) untuk mengimplementasikan struktur data Queue.
```cpp
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
```

## Tugas

**1. Reverse a Stack**
Pada fungsi reverseStack, langkah pertama adalah memindahkan semua elemen dari tumpukan ke antrian. Kemudian, langkah kedua adalah memindahkan semua elemen dari antrian kembali ke tumpukan. Hal ini akan menghasilkan tumpukan yang sudah dibalik.
```cpp
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
```
**2. Reverse a Queue**
Pada fungsi reverseQueue, langkah pertama adalah mendekripsi semua elemen dari antrian ke tumpukan. Kemudian, langkah kedua adalah memindahkan semua elemen dari tumpukan kembali ke antrian. Hal ini akan menghasilkan antrian yang sudah dibalik.
```cpp
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
```
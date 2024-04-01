// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

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
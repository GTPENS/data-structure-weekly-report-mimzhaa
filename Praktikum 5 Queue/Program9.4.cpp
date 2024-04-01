// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

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
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* tail=NULL;

void buat(Node*& head, int a);
void buatAwal(Node*& head, int a);
void tampil(Node* head);
void forTail(Node* head, Node*& tail);
void sisipkanSetelah(Node*& head, int after, int value);
void sisipkanSebelum(Node*& head, int before, int value);
void pencari(Node*& head, int i);
void hapus(Node*& head);
void hpsNodeIndex(Node *&head, int index);
void hpsNodeData(Node *&head, int data);

int main(){
    Node* head=NULL;
    buat(head, 10);
    tampil(head);
    buat(head, 30);
    tampil(head);
    buat(head, 47);
    tampil(head);
    buat(head, 76);
    tampil(head);
    sisipkanSetelah(head, 30, 45);
    tampil(head);
    sisipkanSebelum(head, 10, 37);
    tampil(head);
    pencari(head, 47);
    tampil(head);
    hpsNodeIndex(head, 2);
    tampil(head);
    hpsNodeData(head, 47);
    tampil(head);
    hapus(head);
}

// 1. Menyisipkan sebagai node awal dari linked list.
void buat(Node*& head, int a){
    cout << "Menambahkan data >> " << a;
    Node* newNode = new Node();
    newNode->data = a;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head; 
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    forTail(head, tail);
}
void buatAwal(Node*& head, int a){
    Node* newNode = new Node();
    newNode->data = a;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head; 
    } else {
        newNode->next=head;
        head=newNode;
    }
}
// 2. Membaca atau menampilkan linked list.
void tampil(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void forTail(Node* head, Node*& tail){
    tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    cout << "\ttail pada : " << tail->data << endl;
}

// 3. Mencari sebuah simpul tertentu.
void pencari(Node*& head, int i){
    Node* cari = head;
    while(cari->data != i){
        cari = cari->next;
    }
    cout << "Pencarian " << cari->data << " " << cari->next << endl;
}

// 4. Menyisipkan setelah simpul tertentu.
void sisipkanSetelah(Node*& head, int after, int value){
    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    while (temp != nullptr && temp->data != after) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Data " << after << " tidak ada" << endl;
    }  
    cout << "Menambahkan data >> " << value << " setelah " << after << endl;
}

// 5. Menghapus simpul tertentu.
void hapus(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// 6. Menyisipkan sebelum simpul tertentu
void sisipkanSebelum(Node*& head, int before, int value){
    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;

    if (head != nullptr && head->data == before) {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (temp != nullptr && temp->next->data != before) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Data " << before << " tidak ada" << endl;
    }  
    cout << "Menambahkan data >> " << value << " sebelum " << before << endl;
}

// 7. Menghapus simpul berdasarkan index.
void hpsNodeIndex(Node *&head, int index){
    cout << "Menghapus node ke-" << index << endl;
    Node* newNode = head;
    Node* bridge = head;
    for(int k=0; k < index; k++){
        newNode = newNode->next;
    }
    for (int i = 0; i < index-1; i++){
        bridge = bridge->next;
    }
    bridge->next = newNode->next;

    delete newNode;
}

// 8. Menghapus simpul berdasarkan data.
void hpsNodeData(Node *&head, int data){
    Node* newNode = head;
    Node* bridge = new Node();
    while(newNode->next->data != data){
        newNode = newNode->next;
    }
    bridge = newNode;
    newNode = newNode->next;
    bridge->next = newNode->next;
    
    delete newNode;
    cout << "Menghapus node dengan nilai " << data << endl;
}
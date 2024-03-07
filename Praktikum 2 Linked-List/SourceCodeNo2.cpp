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
    int nilai,after, before;

    int pilihan;
    do{
        cout << "\nMenu Pilihan:\n";
        cout << "1. Menyisipkan sebagai node dari linked list.\n";
        cout << "2. Membaca atau menampilkan linked list.\n";
        cout << "3. Mencari sebuah simpul tertentu.\n";
        cout << "4. Menyisipkan sebagai simpul terakhir.\n";
        cout << "5. Keluar.\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai yang ingin disisipkan: ";
                cin >> nilai;
                buatAwal(head, nilai);
                break;
            case 2:
                tampil(head);
                break;
            case 3:
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilai;
                pencari(head, nilai);
                break;
            case 4:
                cout << "Masukkan nilai yang ingin disisipkan: ";
                cin >> nilai;
                buat(head, nilai);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);
    
    return 0;
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
void buat(Node*& head, int a){
    cout<<"menambahkan data >> "<<a;
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
void tampil(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void forTail(Node* head, Node*& tail){
    tail=head;
    while(tail->next != NULL){
        tail=tail->next;
    }
    cout<<"\ttail pada : "<<tail->data<<endl;
}
void pencari(Node*& head, int i){
    Node* cari=head;
    while(cari->data!=i){
        cari=cari->next;
    }
    cout<<"pencarian "<<cari->data<<" "<<cari->next<<endl;
}
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
        cout << "data " << after << " tidak ada" << endl;
    }  
    cout<<"menambahkan data >> "<<value<<" setelah "<<after<<endl;
}
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
        cout << "data " << before << " tidak ada" << endl;
    }  
    cout<<"menambahkan data >> "<<value<<" sebelum "<<before<<endl;
}
void hapus(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void hpsNodeIndex(Node *&head, int index){
    Node* newNode=head;
    Node* bridge=head;
    for(int k=0;k<index;k++){
        newNode=newNode->next;
    }
    for (int i = 0; i < index-1; i++){
        bridge=bridge->next;
    }
    bridge->next=newNode->next;

    delete newNode;
    cout<<"menghapus node ke-"<<index<<endl;
}

void hpsNodeData(Node *&head, int data){
    Node* newNode=head;
    Node* bridge=new Node();
    while(newNode->next->data!=data){
        newNode=newNode->next;
    }
    bridge=newNode;
    newNode=newNode->next;
    bridge->next=newNode->next;
    
    delete newNode;
    cout<<"menghapus node dengan nilai "<<data<<endl;
}
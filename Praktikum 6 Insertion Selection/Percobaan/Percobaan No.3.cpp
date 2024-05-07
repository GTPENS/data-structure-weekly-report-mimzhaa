// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

int Data[MAX];

// Fungsi untuk menukar nilai antara dua variabel
void Menukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mengurutkan array menggunakan metode Selection Sort
void Urutkan() {
    int i, j, k;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        for (j = i + 1; j < MAX; j++) {
            if (Data[k] > Data[j]) {
                k = j;
            }
        }
        Menukar(&Data[i], &Data[k]);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Inisialisasi random seed dengan waktu saat ini

    std::cout << "DATA SEBELUM DIURUTKAN";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1;  // Menghasilkan bilangan acak antara 1 dan 1000
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    Urutkan(); // Melakukan pengurutan

    std::cout << "\nDATA SETELAH DIURUTKAN";
    for (int i = 0; i < MAX; i++) {
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    return 0;
}
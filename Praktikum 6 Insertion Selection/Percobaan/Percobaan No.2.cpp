// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

int Data[MAX];

// Prototype fungsi untuk Binary Insertion Sort
void BinaryInsertSort();

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));  // Inisialisasi seed berdasarkan waktu sekarang
    std::cout << "DATA SEBELUM TERURUT";

    // Mengisi array dengan bilangan acak
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1; // Menghasilkan bilangan acak antara 1 dan 1000
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    BinaryInsertSort(); // Melakukan sorting

    std::cout << "\nDATA SETELAH TERURUT";
    for (int i = 0; i < MAX; i++) {
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    return 0;
}

// Implementasi Binary Insertion Sort
void BinaryInsertSort() {
    for (int i = 1; i < MAX; i++) {
        int x = Data[i];
        int l = 0;
        int r = i - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (x < Data[m])
                r = m - 1;
            else
                l = m + 1;
        }

        for (int j = i - 1; j >= l; j--)
            Data[j + 1] = Data[j];

        Data[l] = x;
    }
}
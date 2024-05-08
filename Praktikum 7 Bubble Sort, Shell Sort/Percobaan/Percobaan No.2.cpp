// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

int Data[MAX];

// Fungsi untuk menukar data
void Tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk melakukan pengurutan Shell
void UrutkanShell() {
    int celah, i, j;
    bool ditukar;
    celah = MAX;

    while (celah > 1) {
        celah = celah / 2;
        ditukar = false;

        while (!ditukar) {
            ditukar = true;
            for (j = 0; j < MAX - celah; j++) {
                i = j + celah;
                if (Data[j] > Data[i]) {
                    Tukar(&Data[j], &Data[i]);
                    ditukar = false;
                }
            }
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Menginisialisasi pengacakan dengan waktu saat ini untuk keacakan yang lebih baik

    // Menghasilkan bilangan acak
    std::cout << "DATA SEBELUM DIURUTKAN";
    for (int i = 0; i < MAX; i++) {
        Data[i] = std::rand() % 100 + 1; // Menghasilkan bilangan acak antara 1 dan 100
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    UrutkanShell(); // Melakukan pengurutan array

    // Menampilkan data yang telah diurutkan
    std::cout << "\nDATA SETELAH DIURUTKAN";
    for (int i = 0; i < MAX; i++) {
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    return 0;
}
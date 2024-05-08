// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define MAX 10

std::vector<int> data(MAX);

// Fungsi untuk menukar nilai antara dua variabel
void Tukar(int *a, int *b, int& tukar) {
    int temp = *a;
    *a = *b;
    *b = temp;
    tukar++;
}

// Fungsi untuk melakukan Bubble Sort dengan menampilkan setiap iterasinya
void UrutkanBubble() {
    bool ditukar;
    int pembanding = 0, tukar = 0;
    for (int i = 0; i < MAX - 1; i++) {
        ditukar = false;
        for (int j = 0; j < MAX - i - 1; j++) {
            pembanding++;
            if (data[j] > data[j + 1]) {
                Tukar(&data[j], &data[j + 1], tukar);
                ditukar = true;
            }
        }
        // Menampilkan keadaan array setelah setiap iterasi
        std::cout << "Setelah iterasi " << i + 1 << ": ";
        for (int k = 0; k < MAX; k++) {
            std::cout << data[k] << " ";
        }
        std::cout << "\n";
        if (!ditukar)
            break; // Jika tidak ada pertukaran berarti array sudah terurut
    }
    std::cout << "Total pembanding: " << pembanding << ", Total pertukaran: " << tukar << "\n";
}

// Fungsi untuk melakukan Shell Sort dengan menampilkan setiap iterasinya
void UrutkanShell() {
    int celah, i, j, pembanding = 0, tukar = 0;
    for (celah = MAX / 2; celah > 0; celah /= 2) {
        bool ditukar;
        do {
            ditukar = false;
            for (j = 0; j < MAX - celah; j++) {
                pembanding++;
                i = j + celah;
                if (data[j] > data[i]) {
                    Tukar(&data[j], &data[i], tukar);
                    ditukar = true;
                }
            }
            // Menampilkan keadaan array setelah setiap iterasi celah
            std::cout << "Setelah celah " << celah << ": ";
            for (int k = 0; k < MAX; k++) {
                std::cout << data[k] << " ";
            }
            std::cout << "\n";
        } while (ditukar);
    }
    std::cout << "Total pembanding: " << pembanding << ", Total pertukaran: " << tukar << "\n";
}

// Fungsi untuk menghasilkan data acak
void HasilkanDataAcak() {
    for (int i = 0; i < MAX; i++) {
        data[i] = std::rand() % 100 + 1;
    }
}

// Fungsi untuk menampilkan data awal
void TampilkanData() {
    std::cout << "Data sebelum diurutkan: ";
    for (int i = 0; i < MAX; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int pilihan;
    bool berjalan = true;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (berjalan) {
        std::cout << "\nMenu:\n1. Bubble Sort\n2. Shell Sort\n3. Keluar\nPilih (1-3): ";
        std::cin >> pilihan;

        if (pilihan == 1 || pilihan == 2) {
            HasilkanDataAcak();
            TampilkanData();

            if (pilihan == 1) {
                std::cout << "Melakukan Bubble Sort...\n";
                UrutkanBubble();
            } else if (pilihan == 2) {
                std::cout << "Melakukan Shell Sort...\n";
                UrutkanShell();
            }

            std::cout << "Data setelah diurutkan: ";
            for (int i = 0; i < MAX; i++) {
                std::cout << data[i] << " ";
            }
            std::cout << "\n";
        } else if (pilihan == 3) {
            berjalan = false; // Keluar dari loop
        } else {
            std::cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    }

    return 0;
}
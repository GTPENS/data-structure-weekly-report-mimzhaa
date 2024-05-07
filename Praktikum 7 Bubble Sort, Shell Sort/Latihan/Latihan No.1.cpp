// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define MAX 10

std::vector<int> data(MAX);

// Function to swap data
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort with display at each iteration
void BubbleSort() {
    bool swapped;
    for (int i = 0; i < MAX - 1; i++) {
        swapped = false;
        for (int j = 0; j < MAX - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                Swap(&data[j], &data[j + 1]);
                swapped = true;
            }
        }
        // Display the array's state after each pass
        std::cout << "Setelah langkah " << i + 1 << ": ";
        for (int k = 0; k < MAX; k++) {
            std::cout << data[k] << " ";
        }
        std::cout << "\n";
        if (!swapped)
            break; // No swaps means the array is sorted
    }
}

// Function to perform Shell Sort with display at each iteration
void ShellSort() {
    int gap, i, j;
    bool swapped;

    for (gap = MAX / 2; gap > 0; gap /= 2) {
        do {
            swapped = false;
            for (j = 0; j < MAX - gap; j++) {
                i = j + gap;
                if (data[j] > data[i]) {
                    Swap(&data[j], &data[i]);
                    swapped = true;
                }
            }
            // Display the array's state after each gap comparison
            std::cout << "Setelah celah " << gap << ": ";
            for (int k = 0; k < MAX; k++) {
                std::cout << data[k] << " ";
            }
            std::cout << "\n";
        } while (swapped);
    }
}

// Function to generate random data
void GenerateRandomData() {
    for (int i = 0; i < MAX; i++) {
        data[i] = std::rand() % 100 + 1;
    }
}

// Function to display the initial data
void DisplayData() {
    std::cout << "Data sebelum pengurutan: ";
    for (int i = 0; i < MAX; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int choice;
    bool running = true;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (running) {
        std::cout << "\nMenu:\n1. Bubble Sort\n2. Shell Sort\n3. Keluar\nPilih (1-3): ";
        std::cin >> choice;

        if (choice == 1 || choice == 2) {
            GenerateRandomData();
            DisplayData();

            if (choice == 1) {
                std::cout << "Melakukan Bubble Sort...\n";
                BubbleSort();
            } else if (choice == 2) {
                std::cout << "Melakukan Shell Sort...\n";
                ShellSort();
            }

            std::cout << "Data setelah pengurutan: ";
            for (int i = 0; i < MAX; i++) {
                std::cout << data[i] << " ";
            }
            std::cout << "\n";
        } else if (choice == 3) {
            running = false; // Keluar dari loop
        } else {
            std::cout << "Pilihan tidak valid, coba lagi.\n";
        }
    }

    return 0;
}
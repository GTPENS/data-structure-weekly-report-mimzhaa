// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

int Data[MAX];

// Function to swap data
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform QuickSort recursively
void QuickSortRecursive(int L, int R) {
    int i = L, j = R;
    int pivot = Data[(L + R) / 2];

    while (i <= j) {
        while (Data[i] < pivot) i++;
        while (Data[j] > pivot) j--;
        if (i <= j) {
            Swap(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }

    if (L < j) QuickSortRecursive(L, j);
    if (i < R) QuickSortRecursive(i, R);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Use current time as seed for random generator

    std::cout << "DATA BEFORE SORTING\n";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1; // Generating numbers between 1 and 100
        std::cout << "Data[" << i << "]: " << Data[i] << "\n";
    }

    std::cout << "\nSorting data using QuickSort recursively...\n";

    QuickSortRecursive(0, MAX - 1);

    std::cout << "\nDATA AFTER SORTING\n";
    for (int i = 0; i < MAX; i++) {
        std::cout << "Data[" << i << "]: " << Data[i] << "\n";
    }

    return 0;
}
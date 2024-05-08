// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define MAX 10

std::vector<int> Data(MAX);
std::vector<int> Temp(MAX);

int comparisons, shifts;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    shifts++;
}

void PrintArray(const std::vector<int>& array, const std::string& prefix) {
    std::cout << prefix;
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void BubbleSort() {
    bool swapped;
    for (int i = 0; i < MAX - 1; i++) {
        swapped = false;
        for (int j = 0; j < MAX - i - 1; j++) {
            comparisons++;
            if (Data[j] > Data[j + 1]) {
                Swap(&Data[j], &Data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void QuickSort(int left, int right) {
    if (left >= right) return;
    int pivot = Data[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (Data[i] < pivot) { i++; comparisons++; }
        while (Data[j] > pivot) { j--; comparisons++; }
        if (i <= j) {
            Swap(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }

    QuickSort(left, j);
    QuickSort(i, right);
}

void Merge(int left, int mid, int right) {
    int i = left, j = mid, k = left;

    while (i <= mid - 1 && j <= right) {
        comparisons++;
        if (Data[i] <= Data[j]) {
            Temp[k++] = Data[i++];
        } else {
            Temp[k++] = Data[j++];
        }
        shifts++;
    }

    while (i <= mid - 1) {
        Temp[k++] = Data[i++];
        shifts++;
    }

    while (j <= right) {
        Temp[k++] = Data[j++];
        shifts++;
    }

    for (i = left; i <= right; i++) {
        Data[i] = Temp[i];
        shifts++;
    }
}

void MergeSort(int left, int right) {
    if (right > left) {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid + 1, right);
    }
}

void InitializeData() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1;
    }
    comparisons = 0;
    shifts = 0;
}

int main() {
    char choice;
    int option;
    
    do {
        InitializeData();
        std::cout << "\nDATA SEBELUM DIURUTKAN: ";
        PrintArray(Data, "");

        std::cout << "Pilih metode pengurutan:\n";
        std::cout << "1. Quick Sort\n";
        std::cout << "2. Merge Sort\n";
        std::cout << "3. Bubble Sort\n";
        std::cout << "Pilihan Anda: ";
        std::cin >> option;

        switch (option) {
            case 1:
                QuickSort(0, MAX - 1);
                break;
            case 2:
                MergeSort(0, MAX - 1);
                break;
            case 3:
                BubbleSort();
                break;
            default:
                std::cout << "Pilihan tidak valid!\n";
                continue;
        }

        std::cout << "\nDATA SETELAH DIURUTKAN: ";
        PrintArray(Data, "");
        std::cout << "Jumlah perbandingan: " << comparisons << "\n";
        std::cout << "Jumlah pergeseran: " << shifts << "\n";

        std::cout << "Ulangi program? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define MAX 10

std::vector<int> Data(MAX);
std::vector<int> Temp(MAX);

void Tukar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void CetakArray(const std::vector<int>& array, const std::string& prefix) {
    std::cout << prefix;
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void QuickSort(int left, int right) {
    if (left >= right) return;
    int pivot = Data[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (Data[i] < pivot) i++;
        while (Data[j] > pivot) j--;
        if (i <= j) {
            Tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }

    CetakArray(Data, "Iterasi Quick Sort: ");
    
    QuickSort(left, j);
    QuickSort(i, right);
}

void Merge(int left, int mid, int right) {
    int i = left, j = mid, k = left;

    while (i <= mid - 1 && j <= right) {
        if (Data[i] <= Data[j])
            Temp[k++] = Data[i++];
        else
            Temp[k++] = Data[j++];
    }

    while (i <= mid - 1)
        Temp[k++] = Data[i++];

    while (j <= right)
        Temp[k++] = Data[j++];

    for (i = left; i <= right; i++)
        Data[i] = Temp[i];

    CetakArray(Data, "Iterasi Merge Sort: ");
}

void MergeSort(int left, int right) {
    if (right > left) {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid + 1, right);
    }
}

void InisialisasiData() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1;
    }
}

int main() {
    char lanjut;
    int pilihan;
    
    do {
        InisialisasiData();
        std::cout << "\nDATA SEBELUM DIURUTKAN: ";
        CetakArray(Data, "");

        std::cout << "Pilih metode pengurutan:\n";
        std::cout << "1. Quick Sort\n";
        std::cout << "2. Merge Sort\n";
        std::cout << "Pilihan Anda: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                QuickSort(0, MAX - 1);
                break;
            case 2:
                MergeSort(0, MAX - 1);
                break;
            default:
                std::cout << "Pilihan tidak valid!\n";
                continue;
        }

        std::cout << "\nDATA SETELAH DIURUTKAN: ";
        CetakArray(Data, "");

        std::cout << "Ulangi program? (y/n): ";
        std::cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}
// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Untuk std::swap

struct Employee {
    std::string id;
    std::string name;
};

std::vector<Employee> employees;

void PrintEmployees() {
    for (auto& emp : employees) {
        std::cout << "ID: " << emp.id << ", Name: " << emp.name << "\n";
    }
}

int Partition(std::vector<Employee>& arr, int low, int high, bool ascending, bool sortById) {
    Employee pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (ascending == (sortById ? (arr[j].id < pivot.id) : (arr[j].name < pivot.name))) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(std::vector<Employee>& arr, int low, int high, bool ascending, bool sortById) {
    if (low < high) {
        int pi = Partition(arr, low, high, ascending, sortById);

        QuickSort(arr, low, pi - 1, ascending, sortById);
        QuickSort(arr, pi + 1, high, ascending, sortById);
    }
}

void Merge(std::vector<Employee>& arr, int l, int m, int r, bool ascending, bool sortById) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<Employee> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (ascending == (sortById ? (L[i].id <= R[j].id) : (L[i].name <= R[j].name))) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<Employee>& arr, int l, int r, bool ascending, bool sortById) {
    if (l < r) {
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m, ascending, sortById);
        MergeSort(arr, m + 1, r, ascending, sortById);
        Merge(arr, l, m, r, ascending, sortById);
    }
}

int main() {
    char choice;
    int sortingMethod, sortingType, sortingDirection;
    do {
        std::cout << "Masukkan data Pegawai (ID dan Nama, ketik 'done' untuk selesai):\n";
        std::string id, name;
        while (true) {
            std::cout << "ID: ";
            std::getline(std::cin, id);
            if (id == "done") break;
            std::cout << "Name: ";
            std::getline(std::cin, name);
            employees.push_back({id, name});
        }

        std::cout << "Pilih metode pengurutan:\n";
        std::cout << "1. Quick Sort\n";
        std::cout << "2. Merge Sort\n";
        std::cin >> sortingMethod;
        std::cin.ignore();

        std::cout << "Pilih tipe pengurutan:\n";
        std::cout << "1. Berdasarkan ID\n";
        std::cout << "2. Berdasarkan Nama\n";
        std::cin >> sortingType;
        std::cin.ignore();

        std::cout << "Pilih arah pengurutan:\n";
        std::cout << "1. Ascending (Naik)\n";
        std::cout << "2. Descending (Turun)\n";
        std::cin >> sortingDirection;
        std::cin.ignore();

        bool ascending = (sortingDirection == 1);
        bool sortById = (sortingType == 1);

        std::cout << "\nData Pegawai sebelum diurutkan:\n";
        PrintEmployees();

        if (sortingMethod == 1) {
            QuickSort(employees, 0, employees.size() - 1, ascending, sortById);
        } else {
            MergeSort(employees, 0, employees.size() - 1, ascending, sortById);
        }

        std::cout << "\nData Pegawai setelah diurutkan:\n";
        PrintEmployees();

        std::cout << "\nUlangi program? (y/n): ";
        std::cin >> choice;
        std::cin.ignore();

        employees.clear();  // Clear the vector for new input if repeated
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
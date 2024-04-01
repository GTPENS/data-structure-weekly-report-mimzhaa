// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& str) {
    stack<char> stack;
    string temp = str;

    // Menghapus spasi dan mengubah ke huruf kecil
    temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    // Mendorong setengah karakter ke dalam stack
    for (int i = 0; i < temp.length() / 2; i++) {
        stack.push(temp[i]);
    }

    // Memulai dari tengah (atau tengah + 1 jika panjang ganjil)
    int start = temp.length() % 2 == 0 ? temp.length() / 2 : (temp.length() / 2) + 1;

    // Memastikan karakter yang sesuai dengan stack
    for (int i = start; i < temp.length(); i++) {
        if (temp[i] != stack.top()) {
            return false;
        }
        stack.pop();
    }

    return true;
}

int main() {
    string str;
    cout << "Masukkan sebuah string: ";
    getline(cin, str);

    cout << "\"" << str << "\" is " << (isPalindrome(str) ? "a palindrome" : "not a palindrome") << endl;

    return 0;
}
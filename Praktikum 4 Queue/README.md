
## Nama    : Marlon Immanuel Sarapang
## NRP     : 52236000010
## Kelas   : GT11-A

# Praktikum 4: Overview Stack

1. **Implementasikan Stack Menggunakan Linked List**

Kelas `ListStack` adalah sebuah representasi dari tumpukan (Stack) yang mengimplementasikan operasi dasar seperti `push` (menambahkan elemen ke dalam tumpukan), `pop` (menghapus elemen dari tumpukan), `peek` (melihat elemen teratas tanpa menghapusnya), `size` (mendapatkan ukuran tumpukan), dan `empty` (memeriksa apakah tumpukan kosong).

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val, Node* n = nullptr) {
        value = val;
        next = n;
    }
};

class ListStack {
private:
    Node* head;
    int count;

public:
    ListStack() {
        head = nullptr;
        count = 0;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    int top() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return head->value;
    }

    void push(int val) {
        head = new Node(val, head);
        count++;
    }

    int pop() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        int val = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return val;
    }
};

int main() {
    ListStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl;
    cout << "Size of stack: " << stack.size() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    return 0;
}
```

2. **Memeriksa Keseimbangan Tanda Kurung**

Mengevaluasi keseimbangan tanda kurung dalam suatu ekspresi dengan menggunakan struktur data Stack, di mana tanda kurung pembuka dimasukkan ke dalam Stack dan dipasangkan dengan tanda kurung penutup yang sesuai.
```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalancedParenthesis(const string& expr) {
    stack<char> stack;
    const string opening = "([{";
    const string closing = ")]}";

    for (char ch : expr) {
        if (opening.find(ch) != string::npos) {
            stack.push(ch);
        } else if (closing.find(ch) != string::npos) {
            if (stack.empty() || opening.find(stack.top()) != closing.find(ch)) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    string expr1 = "{()}";
    string expr2 = "{())}";

    cout << "Expression: " << expr1 << " is "
         << (isBalancedParenthesis(expr1) ? "balanced" : "not balanced") << endl;
    cout << "Expression: " << expr2 << " is "
         << (isBalancedParenthesis(expr2) ? "balanced" : "not balanced") << endl;

    return 0;
}
```

3. **Konversi Infix ke Postfix**

Mengubah ekspresi matematika dari format infix menjadi postfix dengan memanfaatkan struktur data Stack untuk mengelola prioritas operator sesuai dengan aturan preseden yang ditetapkan.
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> stack;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            }
        } else {
            while (!stack.empty() && precedence(ch) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);

    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
```

4. **Konversi Infix ke Prefix**

Mengubah ekspresi matematika dari notasi infix ke prefix dengan cara mengambil ekspresi infix, membaliknya terlebih dahulu, kemudian mengonversinya ke postfix, dan terakhir, membalik kembali hasilnya untuk mendapatkan ekspresi prefix.
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

string infixToPrefix(const string& infix) {
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (int i = 0; i < reversedInfix.length(); i++) {
        if (reversedInfix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (reversedInfix[i] == ')') {
            reversedInfix[i] = '(';
        }
    }

    stack<char> stack;
    string prefix;

    for (char ch : reversedInfix) {
        if (isalnum(ch)) {
            prefix += ch;
        } else if (ch == ')') {
            stack.push(ch);
        } else if (ch == '(') {
            while (!stack.empty() && stack.top() != ')') {
                prefix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == ')') {
                stack.pop();
            }
        } else {
            while (!stack.empty() && stack.top() != ')' &&
                   ((ch != '^' && precedence(ch) <= precedence(stack.top())) ||
                    (ch == '^' && precedence(ch) < precedence(stack.top())))) {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string prefix = infixToPrefix(infix);

    cout << "Infix expression: " << infix << endl;
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
```

5. **Evaluasi Ekspresi Postfix**

Menjalankan evaluasi terhadap ekspresi postfix dengan meletakkan operand ke dalam Stack dan melaksanakan operasi aritmatika yang sesuai tergantung operator yang diidentifikasi.
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(const string& postfix) {
    stack<int> stack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            switch (ch) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return stack.top();
}

int main() {
    string postfix = "83+72*-";
    int result = evaluatePostfix(postfix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Result: " << result << endl;

    return 0;
}
```

6. **Palindrome String menggunakan Stack**

Untuk menentukan apakah suatu string adalah palindrom atau tidak, langkahnya adalah membandingkan setengah karakter pertama yang dimasukkan ke dalam Stack dengan setengah karakter kedua.
```cpp
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
```



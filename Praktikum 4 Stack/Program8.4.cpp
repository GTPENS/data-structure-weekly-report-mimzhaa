// Nama: Marlon Immanuel Sarapang
// NRP: 5223600010

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
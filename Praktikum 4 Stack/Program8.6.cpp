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
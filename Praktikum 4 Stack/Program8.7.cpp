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
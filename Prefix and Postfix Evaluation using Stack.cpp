#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

int evaluatePrefix(string exp) {
    stack<int> s;

    for (int i = exp.size() - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        } else {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();

            switch (exp[i]) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
                case '^': s.push(pow(op1, op2)); break;
            }
        }
    }
    return s.top();
}
/*The expression (exp[i] - '0') is used to convert a character representing a digit to its corresponding integer value. Here's how it works:

Character to Integer Conversion
In C++, characters are stored as their ASCII values. For instance:

'0' has an ASCII value of 48
'1' has an ASCII value of 49
'2' has an ASCII value of 50
And so on...
When you subtract '0' from a character representing a digit (e.g., '3'), you get the integer value of that digit. For example:

'3' - '0' results in 51 - 48, which equals 3.*/

int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.size(); i++) {
        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        } else {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();

            switch (exp[i]) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
                case '^': s.push(pow(op1, op2)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string prefix_exp = "-+8/632";
    string postfix_exp = "86+3/2-";

    cout << "Prefix evaluation: " << evaluatePrefix(prefix_exp) << endl;
    cout << "Postfix evaluation: " << evaluatePostfix(postfix_exp) << endl;

    return 0;
}

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix
/*you can change cerr to cout for error messages if you prefer. However, it's a common convention to use cerr for error output because
cerr is typically unbuffered and is meant for error messages or diagnostics that should be immediately displayed, whereas cout
 is buffered and used for general output*/
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;
    
    for (char c : infix) {
        if (isalnum(c)) {  // If operand, add to postfix
            postfix += c;
        } else if (c == '(') {  // If '(', push to stack
            s.push(c);
        } else if (c == ')') {  // If ')', pop and add to postfix until '('
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Pop '(' from stack
        } else {  // If operator
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    // Pop all remaining operators in stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

// Function to convert infix expression to prefix
string infixToPrefix(string infix) {
    string reversedInfix;
    for (int i = infix.size() - 1; i >= 0; --i) {
        if (infix[i] == '(')
            reversedInfix += ')';
        else if (infix[i] == ')')
            reversedInfix += '(';
        else
            reversedInfix += infix[i];
    }

    string postfix = infixToPostfix(reversedInfix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> s;
    
    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            if (s.size() < 2) {
                cerr << "Error: Insufficient operands for operator '" << c << "'" << endl;
                return 0; // Or handle error in another appropriate way
            }
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            
            switch (c) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
                case '^': s.push(pow(op1, op2)); break;
                default:
                    cerr << "Error: Unknown operator '" << c << "'" << endl;
                    return 0; // Or handle error in another appropriate way
            }
        }
    }
    
    if (s.size() != 1) {
        cerr << "Error: Invalid expression format" << endl;
        return 0; // Or handle error in another appropriate way
    }
    
    return s.top();
}

// Function to evaluate prefix expression
int evaluatePrefix(string prefix) {
    stack<int> s;
    
    for (int i = prefix.size() - 1; i >= 0; --i) {
        if (isdigit(prefix[i])) {
            s.push(prefix[i] - '0');
        } else {
            if (s.size() < 2) {
                cerr << "Error: Insufficient operands for operator '" << prefix[i] << "'" << endl;
                return 0; // Or handle error in another appropriate way
            }
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            
            switch (prefix[i]) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
                case '^': s.push(pow(op1, op2)); break;
                default:
                    cerr << "Error: Unknown operator '" << prefix[i] << "'" << endl;
                    return 0; // Or handle error in another appropriate way
            }
        }
    }
    
    if (s.size() != 1) {
        cerr << "Error: Invalid expression format" << endl;
        return 0; // Or handle error in another appropriate way
    }
    
    return s.top();
}

int main() {
    string infix_exp ;
    cout<<"Enter your expression"<<endl;
    cin>>infix_exp;
    
    // Convert infix to postfix and prefix
    string postfix_exp = infixToPostfix(infix_exp);
    string prefix_exp = infixToPrefix(infix_exp);
    
    // Evaluate postfix expression
    int postfix_result = evaluatePostfix(postfix_exp);
    
    // Evaluate prefix expression
    int prefix_result = evaluatePrefix(prefix_exp);
    
    // Output results
    cout << "Infix Expression: " << infix_exp << endl;
    cout << "Postfix Expression: " << postfix_exp << endl;
    cout << "Prefix Expression: " << prefix_exp << endl;
    cout << "Postfix Evaluation Result: " << postfix_result << endl;
    cout << "Prefix Evaluation Result: " << prefix_result << endl;
    
    return 0;
}

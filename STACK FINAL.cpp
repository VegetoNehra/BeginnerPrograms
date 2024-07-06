#include <iostream>
using namespace std;

const int MAX = 4; // Define the maximum size of the stack
int stack[MAX];
int counter = 0;

void push(int a) {
    if (counter < MAX) {
        stack[counter] = a;
        counter++;
    } else {
        cout << "Stack overflow" << endl;
    }
}

void pop() {
    if (counter > 0) {
        counter--;
    } else {
        cout << "Stack underflow" << endl;
    }
}

void display() {
    for (int i = 0; i < counter; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int top() {
    if (counter > 0) {
        return stack[counter - 1];
    } else {
        cout << "Stack is empty" << endl;
        return -1; // Return a sentinel value to indicate an empty stack
    }
}

int main() {
    int a, b ,c , d,e;
    cin >> a;
    cin >> b;
    cin >> c;
    cin>>d;
    cin>>e;
    push(a);
    push(b);
    push(c);
    push(d);
    push(e);
    display();
    cout << "Top element: " << top() << endl;
    pop();
    display();
    cout << "Top element: " << top() << endl;
    pop();
    display();
    cout << "Top element: " << top() << endl;
    pop(); // This should show an underflow error
    return 0;
}


#include <iostream>
using namespace std;

class Stack {
private:
    int* stack;
    int capacity;
    int counter;

    // Function to resize the stack when it overflows
    void resize() {
        capacity *= 2; // Double the capacity
        int* newStack = new int[capacity]; // Allocate new memory
        for (int i = 0; i < counter; i++) {
            newStack[i] = stack[i]; // Copy elements to the new stack
        }
        delete[] stack; // Free old memory
        stack = newStack; // Update the stack pointer
    }

public:
    Stack(int size = 4) : capacity(size), counter(0) {
        stack = new int[capacity];
    }

    ~Stack() {
        delete[] stack;
    }

    void push(int a) {
        if (counter == capacity) {
            resize(); // Resize if the stack overflows
        }
        stack[counter] = a;
        counter++;
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
};

int main() {
    Stack s;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    s.push(a);
    s.push(b);
    s.push(c);
    s.push(d);
    s.push(e);
    s.display();
    cout << "Top element: " << s.top() << endl;
    s.pop();
    s.display();
    cout << "Top element: " << s.top() << endl;
    s.pop();
    s.display();
    cout << "Top element: " << s.top() << endl;
    s.pop(); // This should show an underflow error if called more than the number of elements in the stack
    return 0;
}

#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // Add elements to the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Display the top element
    std::cout << "Top element: " << s.top() << std::endl;

    // Remove the top element
    s.pop();

    // Display the top element again
    std::cout << "Top element after pop: " << s.top() << std::endl;

    // Display the size of the stack
    std::cout << "Stack size: " << s.size() << std::endl;

    return 0;
}

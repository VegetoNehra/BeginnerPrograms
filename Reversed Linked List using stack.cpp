#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtHead(int value) {
        Node* newnode = new Node(value);
        if (head == nullptr) {
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseUsingStack() {
        if (head == nullptr || head->next == nullptr)
            return;

        stack<Node*> st;
        Node* current = head;

        // Push all nodes onto the stack
        while (current != nullptr) {
            st.push(current);
            current = current->next;
        }

        // Pop from stack to reverse the list
        head = st.top();
        st.pop();
        current = head;

        while (!st.empty()) {
            current->next = st.top();
            st.pop();
            current = current->next;
        }
        current->next = nullptr; // Set the last node's next to nullptr
    }
};

int main() {
    LinkedList list;
    list.insertAtHead(10);
    list.display();

    list.insertAtHead(20);
    list.display();

    list.insertAtHead(30);
    list.display(); // Output should be: 30 20 10

    list.reverseUsingStack();
    cout << "Reversed list:" << endl;
    list.display();

    return 0;
}

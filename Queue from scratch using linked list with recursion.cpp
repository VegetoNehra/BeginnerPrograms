#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            displayRecursive(head); // Call private recursive display function
        }
    }

    void displayReverse() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            displayReverseRecursive(head); // Call private recursive reverse display function
        }
    }

    void insert(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) { // If the queue was empty
                tail = newNode;
            }
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Position out of bounds." << std::endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr) { // If inserted at the end
            tail = newNode;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        tail = head; // Update tail to point to the original head

        while (current != nullptr) {
            next = current->next; // Store next node
            current->next = prev; // Reverse current node's pointer
            prev = current; // Move pointers one position ahead
            current = next;
        }
        head = prev; // Update head to point to the new head (previous tail)
    }

private:
    void displayRecursive(Node* current) {
        if (current == nullptr) {
            std::cout << std::endl; // to implement a newline character
            return;
        }
        std::cout << current->data << " ";
        displayRecursive(current->next);

    }

    void displayReverseRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }
        displayReverseRecursive(current->next);
        std::cout << current->data << " ";
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.insert(15, 1); // Insert 15 at position 1
    q.display();

    q.insert(5, 0); // Insert 5 at position 0 (head)
    q.display();

    q.reverse();
    q.display();

    q.insert(35, 4); // Insert 35 at position 4 (end)
    q.display();

    q.insert(40, 10); // Attempt to insert at an out-of-bounds position
    q.display();

    std::cout << "Display in reverse order:" << std::endl;
    q.displayReverse();
    
    q.display();

    return 0;
}

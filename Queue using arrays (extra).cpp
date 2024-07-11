#include <iostream>
#define MAX_SIZE 100  // Define the maximum size of the queue

class Queue {
private:
    int front, rear, size;
    int arr[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full!" << std::endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        size++;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        if (size == 0) {
            front = -1;
            rear = -1;
        }
        return value;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == MAX_SIZE;
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return arr[front];
    }

    // Function to get the current size of the queue
    int getSize() {
        return size;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element: " << q.getFront() << std::endl;

    std::cout << "Dequeued element: " << q.dequeue() << std::endl;

    std::cout << "Front element: " << q.getFront() << std::endl;

    return 0;
}

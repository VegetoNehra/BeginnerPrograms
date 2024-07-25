#include <iostream>
#include <queue>

using namespace std;

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Add elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Check if the queue is not empty using !q.empty()
    if (!q.empty()) {
        cout << "Queue is not empty. Elements are: ";
        displayQueue(q);
    } else {
        cout << "Queue is empty." << endl;
    }

    return 0;
}

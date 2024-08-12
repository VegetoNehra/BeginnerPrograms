#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
private:
    vector<int> heap;

    // Helper method to heapify a subtree rooted at index i
    void heapify(int i, int size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest, size);
        }
    }

    // Helper method to find the index of a specific element
    int findElementIndex(int element) const {
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == element) {
                return i;
            }
        }
        return -1; // Element not found
    }

public:
    // Constructor to create a heap from an array
    Heap(const vector<int>& array) {
        heap = array;
        int size = heap.size();
        // Build the max heap
        for (int i = size / 2 - 1; i >= 0; --i) { // size/2-1 bcoz this is the last non-leafnode , it saves unnecessary comparisons and make it more efficient
            heapify(i, size);
        }
    }

    // Method to perform heapsort
    void heapsort() {
        int size = heap.size();
        for (int i = size - 1; i > 0; --i) {
            swap(heap[0], heap[i]);
            heapify(0, i);
        }
    }

    // Method to delete a specific element
    void deleteElement(int element) {
        int index = findElementIndex(element);
        if (index == -1) {
            cout << "Element not found in the heap" << endl;
            return;
        }

        // Replace the element to be deleted with the last element
        heap[index] = heap.back();
        heap.pop_back();

        // Restore heap property
        heapify(index, heap.size());
    }

    // Method to print the heap
    void printHeap() const {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> array = {4, 10, 3, 5, 1};

    // Create a Heap object
    Heap heap(array);

    cout << "Max Heap:" << endl;
    heap.printHeap();

    // Perform heapsort
    heap.heapsort();

    cout << "Sorted Array:" << endl;
    heap.printHeap();

    // Delete a specific element (for example, 10)
    cout << "Deleting element 10:" << endl;
    heap.deleteElement(10);
    heap.printHeap();

    return 0;
}
